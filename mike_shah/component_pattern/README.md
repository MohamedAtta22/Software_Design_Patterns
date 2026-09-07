# Component Pattern

## What is Component Pattern

- it allows a single entity to span multiple domains without coupling the domains to each other

## pros and cons

### Pros

- We have the flexibility at runtime to add or remove components as needed
- We only carry the components that we need.
- Our 'update' is trivial (Just call update on all the components)

### Compromise

- Can only store 1-type of each component
  - (However, can derive a base class from the component and swap behavior as needed, which gives us some flexibility)
  - Can consider a 'table' of components, and write a 'GetAllComponentsOfType' member function.

### Cons

- This structure as it is, may not meet our secondary goal of performance.
  - Still lots of indirection
  - Cache issues remain
- Components 'Update' in the order that they are added
  - (i.e. two different GameObjects may update in different orders)

## Trade-offs with data-oriented design

### Pros

- Potentially the best performance of all of our designs!
  - We'll still have to look at the implementation and measure but any CPU memory bound operation has great potential for speedup!

### Cons

- Complexity slightly higher -- we'll need 'systems' and 'component managers'

### Considerations

- May not be worth it if components need to communicate and share lots of data
