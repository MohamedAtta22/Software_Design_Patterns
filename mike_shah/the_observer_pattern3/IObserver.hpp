#pragma once
#include "ISubject.hpp"
#include<string>

// Abstract class which we derive from
// 'Base Class'
class IObserver{
    public:
        virtual ~IObserver() {}
        virtual void OnNotify() = 0;
};

// Concrete implementation of our IObserver
class Watcher : public IObserver {
    public:
    // We will automatically register our watcher to a subject
    // when we create it
        explicit Watcher(ISubject& subject, const std::string& name);

        // We will automatically remove our watcher from whatever subject 
        // `ISubject` that it is observing
        ~Watcher();
        
        void OnNotify();

    private:
        std::string mName;
        ISubject& mSubject;      
};
