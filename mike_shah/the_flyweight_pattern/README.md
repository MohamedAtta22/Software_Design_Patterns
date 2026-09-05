# The Flyweight Pattern

- Flyweight pattern is a structural design pattern
- "A flyweight is a shared object that can be used in multiple contexts simultaneously" (GOF book)
- We use the flyweight pattern to help us with solving our particular problem:
  - When we have a large number of objects sharing a common properties
    - Thus we want to save memory (i.e. space)
      - And as a side-effect, often also improve performance.

## What is a Structural Design Pattern

- In short, structural patterns are about 'code organization'
  - Two mechanisms for code organization in languages supporting Object-oriented programming (CPP) are:
    - Inheritance
    - Composition

## Pros and Cons

### Pros

- Can greatly increase the performance of your program
  - Both in terms of memory usage being reduced and actual performance of application (shared data provides potentially good temporal locality)

### Neutral

- Because we are 'sharing' resources 'consistency' is a byproduct, which may generate a 'more correct' result (i.e. All of our geometry is the same in a 3D mesh)
- Careful with shared_ptr and potential performance issues if that's your mechanism -- need to measure first.

### Cons

- You loose fine grain control of every single object
- Some additional complexity added
  - (e.g. Resource managers/factories and the division of objects into intrinsic and extrinsic state)
