#include<iostream>
#include<memory>

// Just the interface we want to enforce, for
// different behaviors (i.e. Part of the strategy pattern)
struct ICombat{
    virtual ~ICombat(){}
    virtual void Execute() = 0;
};

struct NoCombat : public ICombat{
    void Execute(){
        std::cout<<"NoCombat::Execute()\n";
    }
};

struct MeleeCombat : public ICombat{
    void Execute(){
        std::cout<<"MeleeCombat::Execute()\n";
    }
};

struct Orc{
    Orc(){
        mCombatStrategy = std::make_unique<NoCombat>();
    }

    void DoActions(){
        mCombatStrategy->Execute();
    }

    void SetCombatStrategy(std::unique_ptr<ICombat>&& c){
        mCombatStrategy = std::move(c);
    }
    private:

    std::unique_ptr<ICombat> mCombatStrategy;
};

int main(){
    Orc orc;
    orc.DoActions();
    orc.SetCombatStrategy(std::make_unique<MeleeCombat>());
    orc.DoActions();

    return 0;
}