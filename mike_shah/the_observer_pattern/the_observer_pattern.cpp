// First Try
#include<string>
#include<iostream>
#include<forward_list>

class Observer{
    public:
    Observer(std::string name): mName(name){
    }

    void OnNotify(){
        std::cout<<mName<<" says Hello\n";
    }

    private:
        std::string mName;
};

class Subject{
    public:
        //Subject(){}
        void AddObserver(Observer* observer){
            mObservers.push_front(observer);
        }
        
        void RemoveObserver(Observer* observer){
            mObservers.remove(observer);
        }

        void NotifyAll(){
            for(auto& o: mObservers){
                o->OnNotify();
            }
        }
    private:
        std::forward_list<Observer*>mObservers;
};

int main(){

    Subject subject;
    Observer observer1("observer-1");
    Observer observer2("observer-2");
    Observer observer3("observer-3");

    subject.AddObserver(&observer1);
    subject.AddObserver(&observer2);
    subject.AddObserver(&observer3);

    subject.NotifyAll();

    subject.RemoveObserver(&observer3);
    std::cout<<std::endl;

    subject.NotifyAll();

    return 0;
}
