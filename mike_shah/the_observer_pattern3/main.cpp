// Fourth Try
#include<iostream>
#include "IObserver.hpp"
#include "ISubject.hpp"


int main(){

    SomeSubject subject;
    Watcher Watcher1(subject, "Watcher-1");
    Watcher Watcher2(subject, "Watcher-2");
    {
    Watcher Watcher3(subject, "Watcher-3");

    // subject.AddObserver(&Watcher1);
    // subject.AddObserver(&Watcher2);
    // subject.AddObserver(&Watcher3);
    }
    subject.NotifyAll();

    //subject.RemoveObserver(&Watcher3);
    std::cout<<std::endl;

    subject.NotifyAll();

    return 0;
}