package com.aaronbedra;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;
import com.rabbitmq.client.DeliverCallback;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

public class EchoWorker {
    private static final String REQUEST_QUEUE = "echo_requests";
    private static final String RESPONSE_QUEUE = "echo_responses";

    public static void main(String[] args) throws IOException, TimeoutException {
        ConnectionFactory connectionFactory = new ConnectionFactory();
        connectionFactory.setHost("localhost");
        Connection connection = connectionFactory.newConnection();
        Channel channel = connection.createChannel();

        channel.queueDeclare(REQUEST_QUEUE, true, false, false, null);
        channel.queueDeclare(RESPONSE_QUEUE, true, false, false, null);

        DeliverCallback deliverCallback = ((consumerTag, message) -> {
            channel.basicPublish("", RESPONSE_QUEUE, null, message.getBody());
        });

        channel.basicConsume(REQUEST_QUEUE, true, deliverCallback, consumerTag -> {});
    }
}
