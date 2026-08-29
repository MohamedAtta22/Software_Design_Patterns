#include"IObserver.hpp"
#include<iostream>

    Watcher::Watcher(ISubject& subject, const std::string& name) : mSubject(subject) ,mName(name){
        mSubject.AddObserver(this);
    }

    Watcher::~Watcher(){
        mSubject.RemoveObserver(this);
    }

    void Watcher::OnNotify() {
        std::cout<< "watcher-"<< mName<<std::endl;
    }
