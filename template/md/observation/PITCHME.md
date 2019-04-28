---?image=template/img/pencils.jpg

# Designing for Observation

+++?image=template/img/spotlight.png&position=top right&size=20% auto
@title[The Details]

@snap[north-west]
Core Audit Requirements
@snapend

@snap[center list-content-concise span-100]
@ol

- Subject
- Object
- Action
- Timestamp

@olend
<br><br>
@snapend

+++

## Everything that a user does should leave these trails

+++

## The only way you can accomplish this is to bake it into your design

+++

## When you get a request, record it

+++

## When you take an action at the direction of a request, record it

+++

## Record it in a way that it can be indexed and searched

+++

## Where do you get it from?

+++

## Basic reads can come from web server logs

+++

## Everything else requires application level logging

+++

## It's a good idea to keep and analyze web server logs, but better to have the application write audit logs

+++

## You get more control over what is logged

+++

## You have more options for timing, behavior, and format of logs

+++

## You get separation of pure audit vs general application logs

+++

## Adding logging can be expensive

+++

## Make sure to consider performance when adding audit trails

+++

## Don't use performance as an excuse

+++

## Just make sure to consider it

+++

### github.com/paper-trail-gem/paper_trail

+++

## If you work in a regulated industry, this is a must

+++

## If you don't, it's still incredibly helpful

+++

## Consider storing it in a db and providing it to users

+++

## But remember that users don't always cause action to take place

+++

## When the system drives activity, it's just as important to record

+++

## Make sure you are able to resolve system activity to machine accounts

+++
@title[Questions]

@snap[center span-100]
![QUESTIONS-4](template/img/questions-4.png)
@snapend
