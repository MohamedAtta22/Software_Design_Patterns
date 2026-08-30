#include "ISubject.hpp"
#include "IObserver.hpp"

ISubject::ISubject(){}
ISubject::~ISubject(){}

// message is our 'enum' {PLAYSOUND, HANDLEPHYSICS, LOG}
void ISubject::AddObserver(int message, IObserver* observer){
        // search for our 'enum'
        auto it = mObservers.find(message);
        if(it==mObservers.end()){
            mObservers[message] = ObserversList();
        }

        mObservers[message].push_front(observer);
}

void ISubject::RemoveObserver(int message, IObserver* observer){
        auto it = mObservers.find(message);
        if(it != mObservers.end()){
            // Found the right bucket (i.e key)
            // Now Iterate through our list
            ObserversList& list = mObservers[message];
            for(ObserversList::iterator li = list.begin();
                                        li != list.end();){
            if((*li==observer)){
                list.remove(observer);
            }else{
                ++li;
            }
        }
    }
}

void ISubject::NotifyAll(){
    // Look through all of our keys
    for(ObserversMap::iterator  it = mObservers.begin();
                                it != mObservers.end();
                                it++){
        for(auto& o: mObservers[it->first]){
            o->OnNotify();
        }
    }
}

void ISubject::Notify(int message){
    for(auto& o: mObservers[message]){
        o->OnNotify();
    }
}
