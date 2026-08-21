# The Factory Pattern

it is a creational design pattern.

The factory method pattern provides a generalized way to create instances of an object and can be a great way to hide implementation details for derived class.

it is based on inheritance and polymorphism, Inheritance-based polymorphism

Pros

- Single Responsibility
- easy to update and is extensible

Cons

- at least two (2) updates to the code, `ObjectType` enum class and `MakeGameObjectFactory`. we can keep them in the same file to manage this.

- you may need several factories
