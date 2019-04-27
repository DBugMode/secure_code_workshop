package com.aaronbedra;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;
import java.util.stream.Collectors;

public class EchoServlet extends HttpServlet {
    private static final String REQUEST_QUEUE = "echo_requests";
    private static final String RESPONSE_QUEUE = "echo_responses";

    private Channel channel;
    private LinkedBlockingQueue<String> responseQueue;

    EchoServlet() throws IOException, TimeoutException {
        ConnectionFactory connectionFactory = new ConnectionFactory();
        connectionFactory.setHost("localhost");
        Connection connection = connectionFactory.newConnection();
        this.channel = connection.createChannel();
        channel.queueDeclare(REQUEST_QUEUE, true, false, false, null);
        channel.queueDeclare(RESPONSE_QUEUE, true, false, false, null);
        this.responseQueue = new LinkedBlockingQueue<>();
        consume();
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String body = request.getReader().lines().collect(Collectors.joining(System.lineSeparator()));

        channel.basicPublish("", REQUEST_QUEUE, null, body.getBytes());

        response.setContentType("text/plain");
        try {
            String responseBody = responseQueue.poll(10, TimeUnit.SECONDS);
            if (responseBody != null) {
                response.setStatus(HttpServletResponse.SC_OK);
                response.getWriter().println(responseBody);
            } else {
                response.setStatus(HttpServletResponse.SC_REQUEST_TIMEOUT);
            }
        } catch (InterruptedException e) {
            response.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);
        }
    }

    private void consume () throws IOException {
        channel.basicConsume(RESPONSE_QUEUE, true, ((consumerTag, message) -> {
            try {
                responseQueue.put(new String(message.getBody()));
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }), consumerTag -> {});
    }
}
