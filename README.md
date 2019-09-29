# python-spring
basic functionalities of spring python

### Dependency Injection


object-graph: object can used to njected into other objects.


### Aspect Oriented Programming


##### Join point
A Join point is an identifiable point in the execution of a
program. This is the place where crosscutting actions are
woven in.

#### Pointcut
A Pointcut is a program construct that selects join points and
collects context at that point.

##### Advice
Advice is code that is to be executed at a join point that has
been selected by a pointcut.

##### Aspect
An Aspect is to AOP what a class is to OOP. It is the central
programming construct where a set of pointcuts and advice are
defined.

##### Advisor/interceptor
An Advisor or interceptor is Spring Python's mechanism

Spring Python provides **dynamic weaving** through the use of **proxies**. Proxies are configured using the IoC container. Calls that are normally targeted at the object are instead routed through the proxy. The proxy evaluates possible pointcuts and applies **Advice**. This is also known as **intercepting**.