#include<iostream>
#include<map>

enum class ComponentType{TEXTURE, COLLISON, POSITION};

struct IComponent{
    virtual void Update() = 0;
    virtual ComponentType GetType() = 0;
};

struct TextureComponent : public IComponent{
    void Update(){std::cout<<"TextureComponent::Update\n";};
    ComponentType GetType(){return ComponentType::TEXTURE;}
};
struct CollisionComponent : public IComponent{
    void Update(){std::cout<<"CollisionComponent::Update\n";};
    ComponentType GetType(){return ComponentType::COLLISON;}
};
struct PositionComponent : public IComponent{
    void Update(){std::cout<<"PositionComponent::Update\n";};
    ComponentType GetType(){return ComponentType::POSITION;}
};

struct GameObject{

    void Update(){
        for(auto& [key, value] : mComponents){
            mComponents[key]->Update();
        }
    }
    // May consider using 'unique_ptr' for components 
    void AddComponent(IComponent* c){
        mComponents[c->GetType()] = c;
    }

    IComponent* GetComponent(ComponentType type){
        auto found = mComponents.find(type);
        if(found != mComponents.end()){
            return found->second; 
        }
        return nullptr;
    }

    std::map<ComponentType, IComponent*> mComponents;
};

int main(){

    GameObject mario;
    TextureComponent tc;
    PositionComponent pc;
    CollisionComponent cc;
    // Add our components
    mario.AddComponent(&tc);
    mario.AddComponent(&pc);
    mario.AddComponent(&cc);
    
    auto retrieveComponent = mario.GetComponent(ComponentType::TEXTURE);
    retrieveComponent->Update();

    mario.Update();

    return 0;
}