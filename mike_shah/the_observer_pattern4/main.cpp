// Third Try
#include<iostream>
#include "IObserver.hpp"
#include "ISubject.hpp"


int main(){

    SomeSubject subject;
    Watcher Watcher1(subject, SomeSubject::PLAYSOUND, "Watcher-1");
    Watcher Watcher2(subject, SomeSubject::PLAYSOUND, "Watcher-2");
    Watcher Watcher3(subject, SomeSubject::LOG, "Watcher-3");

    subject.NotifyAll();

    std::cout<<std::endl;

    subject.Notify(SomeSubject::LOG);

    std::cout<<std::endl;

    subject.Notify(SomeSubject::PLAYSOUND);

    return 0;
}
