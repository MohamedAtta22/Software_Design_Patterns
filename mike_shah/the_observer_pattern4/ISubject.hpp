#pragma once
#include<forward_list>
#include<map>

class IObserver;

class ISubject{
    public:
        ISubject();
        virtual ~ISubject();

        virtual void AddObserver(int message, IObserver* observer);
        virtual void RemoveObserver(int message, IObserver* observer);

        void NotifyAll();

        void Notify(int message);
        
    private:
        typedef std::forward_list<IObserver*> ObserversList;
        typedef std::map<int, ObserversList>  ObserversMap;
        // key/value pair
        // key   = is an 'int' or (enum) in this simple demo
        // value = std::forward_list of our observers
        ObserversMap mObservers;
};

class SomeSubject : public ISubject {
    public:
        enum MessageTypes{PLAYSOUND, HANDLEPHYSICS, LOG};
};