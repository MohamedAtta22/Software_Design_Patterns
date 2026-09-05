#include <iostream>
#include <map>

struct Tree{
    // Extrinsic state
    float x,y,z;
    Tree(float _x, float _y, float _z) : x(_x), y(_y), z(_z){

    }
};


// 'Flyweight' - this is what we want to share
struct Model{
    // Intrinsic state (i.e. 'Shared state') within the flyweight
    // - All instances are shared
    struct Mesh{
        int data[100];
    };
    
    Mesh m;
    // Bark b;
    // Leaves l;

    void DrawOperation(const Tree& extrinsicState){
        std::cout   << extrinsicState.x << ","
                    << extrinsicState.y << ","
                    << extrinsicState.z << std::endl;
    }

};

// Note: We could also 'template' our factory on the 'value'
struct FlyweightModelFactory{
    std::map<std::string, Model*> mModelFlyweights;
    
    // Get an existing flyweight, or otherwise create a new
    // 'model' that we can retrieve/share multiple times
    Model* GetFlyweight(std::string key){
        auto iter = mModelFlyweights.find(key);
        if(iter != mModelFlyweights.end()){
            std::cout<<"reusing: "<<key<<std::endl;
            return iter->second;
        }else{
            Model* m = new Model;
            mModelFlyweights[key] = m;
            return m;
        }
    }
};

int main(){

    Tree t1(1.0f, 2.0f, 3.0f);
    Tree t2(4.0f, 5.0f, 6.0f);
    Tree t3(7.0f, 8.0f, 9.0f);

    // Model m;

    // m.DrawOperation(t1);
    // m.DrawOperation(t2);

    FlyweightModelFactory factory;

    factory.GetFlyweight("oak tree")->DrawOperation(t1);
    factory.GetFlyweight("palm tree")->DrawOperation(t2);
    factory.GetFlyweight("oak tree")->DrawOperation(t3);

    return 0;
}
