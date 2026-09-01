#include<iostream>
#include<vector>

// Base Class
struct Monster{
    virtual ~Monster(){}
    virtual void sing() = 0;
};

struct Orc : public Monster{
    Orc(){std::cout<<"Orc::Orc()\n";}
    void sing(){
        std::cout<<"Orc::sing()\n";
    }
};

struct Goblin : public Monster{
    Goblin(){std::cout<<"Goblin::Goblin()\n";}
    void sing(){
        std::cout<<"Goblin::sing()\n";
    }
};


int main(){
    std::vector<Monster*> monsters;
    monsters.emplace_back(new Orc);
    monsters.emplace_back(new Goblin);
    
    for(const auto& m: monsters){
        m->sing();
    }

    return 0;
}