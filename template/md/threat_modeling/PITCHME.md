---?image=template/img/pencils.jpg

# Threat Modeling

+++?image=template/img/bg/black.jpg&position=right&size=50% 100%
@title[Why]

@snap[east span-30]
![](template/img/death.png)
@snapend

@snap[west span-35]
![](template/img/money.png)
@snapend

@snap[south-west template-note text-gray]
Keep asking why
@snapend

@snap[south-east template-note text-white]
until you hit one of these
@snapend

+++

## If there isn't a reason, stop doing it!

+++

```log
120.52.120.5 - - [05/Nov/2017:03:21:45 -0500]
"POST /xmlrpc.php HTTP/1.0" 403 3652 "-"
"Mozilla/5.0 (compatible; Googlebot/2.1;
http://www.google.com/bot.html)"
```

+++?image=template/img/boardroom.png&color=white

+++

## Why is this important?

+++

## It's the entire reason you're doing this!

+++

## This is as much about business as it is security

+++?image=template/img/spotlight.png&position=top right&size=20% auto
@title[The Details]

@snap[north-west]
Threat Modeling Details
@snapend

@snap[south-west list-content-concise span-100]
@ol

- Threat modeling determines where and how
- Threat modeling helps focus on what's important
- Threat modeling identifies unknowns
- Threat modeling identifies design flaws
- Threat modeling helps build risk registers
- Threat modeling helps communicate to everyone

@olend
<br><br>
@snapend

+++

## Security should always come with purpose and intent

+++

## You should understand threats before you design controls

+++?image=template/img/bear.png&size=auto 60%&color=white

+++

## How do we understand threats?

+++

<p style="text-align: left">“Threat modeling is a procedure for optimizing network security by identifying objectives and vulnerabilities, and then defining countermeasures to prevent, or mitigate the effects of, threats to the system.”</p>
  
<p style="text-align: right;">—TechTarget Search Security</p>

+++

## Drawing, documenting, prioritizing

+++

## We're not going to cover methodologies

+++

## Let's ignore the rules and start small

+++?image=template/img/spotlight.png&position=top right&size=20% auto

@snap[north-west]
First
@snapend

@snap[south-west list-content-concise span-100]
@ol

- Open your system diagram(s)
- For every line, add a protocol
- For every box
  - Add the assets in transit and at rest
  - Add the controls in play
- Draw boundaries around logical networks

@olend
<br><br>
@snapend

+++

+++?image=template/img/spotlight.png&position=top right&size=20% auto

@snap[north-west]
Second
@snapend

@snap[south-west list-content-concise span-100]
@ol

- Identify assets with weak or missing controls
- Identify all points of entry into the system
- List the business objectives, goals, and risks
- Map business risks to assets missing controls
- Rank your list of findings by criticality

@olend
<br><br>
@snapend

+++?image=template/img/diagram.png&color=white&size=auto 60%

+++

## Once you have a foundation, create attack scenarios

+++?image=template/img/threats.png&color=white&size=auto 60%

+++

## Focus on reality

+++

## Clearly define the capabilities of the threat actor

+++

## Understand the true business impact

+++

## Derive risk

+++?image=template/img/fair.png

+++

## Notebook Demo

+++

## We've run into our first problem

+++

## Threat Event Frequency

+++

## How often will a threat actor act in a way that could result in a loss?

+++

# ¯\\\_(ツ)\_/¯

+++?image=template/img/scenario.png&color=white&size=auto 90%

+++

## In order to determine risk we need to identify how often

+++

## We have this information

+++

## We have to apply it

+++

## We can do this with a Security Information & Event Management (SIEM) tool

+++

## Or via custom tooling

+++

## Analysis Demo

+++

## Whatever you do, use the data!

+++

## Deliver value, focus, and prioritize

+++

## Threat Modeling Is a Vehicle for Thought

+++

## Much like (T|X|C|D|R)DD

+++

## It lets you focus on controls both strategically and tactically

+++

## And it all ties back to risk

+++

## Active risk registers tell everyone the story

+++

## It keeps everyone informed on current active risk

+++

## And lets them react to quantified risk information

+++

## It lets everyone get involved

+++

## It lets everyone make informed decisions

+++

## Remember

+++

## You can't do it all

+++

## You especially can't do it all well

+++

## Learn to focus on what matters

+++
@title[Questions]

@snap[east span-30]
![QUESTIONS-4](template/img/questions-4.png)
@snapend

@snap[west span-70]
threatmodelingbook.com
amzn.to/2o2RDaE
github.com/abedra/fair_notebook
@snapend
