// Second Try
#include<string>
#include<iostream>
#include<forward_list>

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
        explicit Watcher(const std::string& name) : mName(name){
        }

        void OnNotify() override{
            std::cout<< "watcher-"<< mName<<std::endl;
        }

    private:
        std::string mName;        
        
};

class ISubject{
    public:
        virtual ~ISubject(){}

        virtual void AddObserver(IObserver* observer){
            mObservers.push_front(observer);
        }
        
        virtual void RemoveObserver(IObserver* observer){
            mObservers.remove(observer);
        }

        void NotifyAll(){
            for(auto& o: mObservers){
                o->OnNotify();
            }
        }
    private:
        std::forward_list<IObserver*>mObservers;
};

class SomeSubject : public ISubject {
    public:
};

int main(){

    SomeSubject subject;
    Watcher Watcher1("Watcher-1");
    Watcher Watcher2("Watcher-2");
    Watcher Watcher3("Watcher-3");

    subject.AddObserver(&Watcher1);
    subject.AddObserver(&Watcher2);
    subject.AddObserver(&Watcher3);

    subject.NotifyAll();

    subject.RemoveObserver(&Watcher3);
    std::cout<<std::endl;

    subject.NotifyAll();

    return 0;
}
