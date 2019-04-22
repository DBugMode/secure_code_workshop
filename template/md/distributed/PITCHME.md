---?image=template/img/pencils.jpg

## Securing Distributed Systems

+++?image=template/img/pencils.jpg

# Securing Microservices

+++?image=template/img/pencils.jpg

# Single Callable Interface

+++

## The last title is actually what this is about

+++

## It's time for an intervention...

+++

## What's with all the callable interfaces?

+++

## Goal: serve information on request

+++?image=template/img/spotlight.png&position=top right&size=20% auto
@title[The Details]

@snap[north-west]
What we have do
@snapend

@snap[south-west list-content-concise span-100]
@ol

- Open the firewall for port 443
- Setup SSL
- Setup load balancing
- Authenticate callers
- Authorize callers
- Do the actual work

@olend
<br><br>
@snapend

+++?image=template/img/spotlight.png&position=top right&size=20% auto
@title[The Details]

@snap[north-west]
What we actually do
@snapend

@snap[south-west list-content-concise span-100]
@ol

- Open the firewall ~~for port 443~~
- ~~Setup SSL~~
- Setup load balancing
- ~~Authenticate callers~~ tokens in a db
- ~~Authorize callers~~
- Do the actual work

@olend
<br><br>
@snapend

+++

## Why go through all the trouble?

+++

## Before you say Kong, Istio, etc.

+++

## All of those tools are treating symptoms

+++

## An external API is the only callable interface you actually need

+++

## And maybe you don't even need that

+++?image=template/img/spotlight.png&position=top right&size=20% auto
@title[The Details]

@snap[north-west]
What we should be doing
@snapend

@snap[center list-content span-100]
@ol

- Close the firewall
- Authenticate to a message queue
- Listen to channels that apply to **this** service
- Do the actual work

@olend
<br><br>
@snapend

+++

## There's no reason to expose an HTTP interface

+++

## Unless that's what you are trying to do

+++

## All the other services don't need to do this

+++

## In fact, you are adding incidental complexity

+++

## What do you do if your services are deployed to places where you can't open the firewall?

+++

## Why does a service need to reply synchronously?

+++

## How do you know what the request was if it failed?

+++

## What's the cost of a request?

+++?image=template/img/spotlight.png&position=top right&size=20% auto
@title[The Details]

@snap[north-west]
The HTTPS Request Lifecycle
@snapend

@snap[south-west list-content-concise span-120]
@ol

- Open a new TCP connection
- Negotiate TLS
- Send a string including with HTTP headers + body
- Block, waiting for a response
- Parse a string with the response into the HTTP parts and the payload parts
- Do the actual work
- Tear down the TCP connection

@olend
<br><br>
@snapend

+++

## Seems like a bit much right?

+++

## What if we did it a different way?

+++?image=template/img/spotlight.png&position=top right&size=20% auto
@title[The Details]

@snap[north-west]
The Message Queue Lifecycle
@snapend

@snap[center list-content-concise span-100]
@ol

- Send a message
- If you see a response, parse it
- Do the actual work

@olend
<br><br>
@snapend

+++

## Ok, so how does this make me more secure?

+++

## No open inbound firewall ports

+++

## You can connect services across previously intractable boundaries

+++

## Not everything has to be "always on"

+++

## Your system can continue to operate during a deployment if messages sit in queues

+++

## Services don't authenticate every request

+++

## Focus shifts to protecting the message broker

+++

## Transport layer encryption can be enforced

+++

## You can record and replay your traffic at will

+++

## Message consumers become finite state machines

+++

## MPS (Message per Service)

+++
@title[Questions]

@snap[center span-70]
![QUESTIONS-4](template/img/questions-4.png)
@snapend

