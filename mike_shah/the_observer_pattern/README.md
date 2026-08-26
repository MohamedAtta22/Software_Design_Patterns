# The Observer Design Pattern

it is a behavioral pattern.

Behavioral Patterns: most of these design patterns are specifically concerned with communication between objects.

the observer pattern is a software design pattern in which an object, named the subject, maintains a list of its dependents, called observers, and notifies them automatically of any state changes, usually by calling one of their methods.

so again, thinking about a simple example, we want to be able to have a mouse-click trigger 1 to many events.

- when the mouse clicks (our subject), a series of events are triggered (by our observers).

Subject (Sometimes also called "Publisher" or "Observable")

- "Subject" or "Observable" it is the thing of interest.
- Can also think of it as a Publisher because it will notify of interesting events.

Observer (Sometimes also called "Subscriber")

- "Observer" because is is waiting to be notified of something interesting.
- "Subscriber" you can think of as "I subscribe to Netflix and am notified on my app when a new movie comes out".

- the Observer does not have to be a class that we are reegistering to a function it could be a function.
