---?image=template/img/pencils.jpg

# Managing Dependencies

+++

## You will write less code than you depend on

+++

## Probably by at least an order of magnitude

+++

## Managing those dependencies is just as important as writing secure code

+++

## Maybe even more

+++

## This isn't easy

+++

```fundamental
npx create-react-app javascript
cd javascript
yarn install
yarn audit

82 vulnerabilities found - Packages audited: 36212
Severity: 63 Low | 9 Moderate | 10 High
```

+++

## ┻━┻ ︵ \\(°□°)/ ︵ ┻━┻

+++

## You will always be chasing your dependencies

+++

## It's incredibly important to keep up

+++

## Upgrade as new versions release

+++

## Who's done **the upgrade from hell**?

+++

## Amortize the cost of upgrades by doing it regularly

+++

## What happens if I don't?

+++

## See Equifax...

+++

## There are plenty of tools to help

+++?image=template/img/spotlight.png&position=top right&size=20% auto
@title[The Details]

@snap[north-west]
Open Source Dependency Tools
@snapend

@snap[south-west list-content-concise span-100]
@ol

- [js] npm audit
- [rb] bundler audit / brakeman
- [py] safety
- [java] Dependency Check
- [.NET] Dependency Check
- [go] Snyk *
- [rs] cargo audit

@olend
<br><br>
@snapend

+++

## Exercise: Install and run this on your project

+++
@title[Questions]

@snap[center span-100]
![QUESTIONS-4](template/img/questions-4.png)
@snapend
