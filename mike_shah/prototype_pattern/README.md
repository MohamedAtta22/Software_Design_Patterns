# Prototype Design Pattern

- Prototype Pattern is a creational design pattern

> It is used when the types of objects to create is determined by a prototypical instance, which is cloned to produce new objects. to avoid the inherent cost of creating a new object when it is prohibitively expensive for a given application.

## When to use Prototype Design Pattern

1. When you have a long setup process, and cloning the object is faster than initializing an object from scratch
   - a. e.g. Imagine an object that is created by streaming in information over a network
     - i. I/O could be slow, unavailable, or otherwise not where you want to spend network bandwidth (for cost or speed purposes)
2. When you want to 'instantiate' a version of your object that varies from your constructor or factories
    - a. Effectively can help you avoid creating 'subclasses' of different types -- just create the prototypes you want, and you can instantiate from those.
