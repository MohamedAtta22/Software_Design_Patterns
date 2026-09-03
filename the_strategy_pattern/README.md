# Strategy Design Pattern

## What is the Strategy Pattern

- In computer programming, the strategy pattern (also known as the policy pattern) is a **behavioral** software design pattern that enables selecting an algorithm at runtime. Instead of implementing a single algorithm directly, code receives run-time instructions as to which in a family of algorithms to use.

## When to use Strategy Design Pattern

### 1. When you have a 'family' of related algorithms that are interchangeable within the 'family'

- a. e.g. different sorts acting on integer data
- b. e.g. different compression algorithms (e.g. lossy vs non-lossy)
- C. e.g. exporting dataset to different text formats (e.g. raw, json, xml, yaml, etc.)
- d. e.g. different graph traversals

### 2. When you want to prevent yourself from redeploying software

- a. i.e. May be able to select another algorithm at run-time instead of a patch.

### 3. To potentially make testing easier

- a. it works well in test-driven development when you have related algorithms.

### 4. You observe that a class has multiple conditional statements in its operations instead of many conditionals, move related conditional branches into their own strategy class.

## Pros and Cons

### Pro

- Provide choice of implementation at run-time

    - Based on workload/data-set that may fluctuate you may

- Potentially more understandable code

    - As opposed to lots of conditional statements, or otherwise an API with many special cases

### Con

- Need to measure performance

    - May have some performance implication passing around objects or a level of indirection

    - Fastest computation likely to 'just do the thing' that you need to do

- May be adding inheritance hierarchies that are not needed

## Recap

### Use the Strategy Pattern When...

- You find yourself working with 'families of algorithms'
- You have lots of 'if-else' or 'switch' statements
    - Simplifying your code with this abstraction may also allow you to create/explore/change your program more freely
- You need a way to change run-time behavior
- You want more testable code
    - (Whether that encourages testing in general, or makes it easier to write tests)
