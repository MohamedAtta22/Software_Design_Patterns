#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<print>

class Alien{
    public:
        int mID;
        std::string mName;
        std::vector<int> mData;

        // Constructor
        Alien(int id, std::string name) : mID(id), mName(name){
        }

        // Copy Constructor
        Alien(const Alien& rhs){
            mID = -1;
            mName = rhs.mName;
            mData = rhs.mData;
        }

        // Clone function
        // It's very explicit, we can parameterize it if we need
        std::unique_ptr<Alien> Clone(){
            std::unique_ptr<Alien> clone = std::make_unique<Alien>(*this);
            return clone;
        }

        // Setup Alien data
        // (Simulating some 'slow' operation for setting up pur object)
        void DataDownload(){
            for(int i = 0; i < 100; i++ ){
                mData.push_back(i);
            }
        }



        // Print for debugging
        void Print(){
        std::println("{0} {1}", mID, mName);
        for(auto elem : mData){
            std::print("{0}",elem);
        }
        std::println("");
        }
};

int main(){

    Alien default_(0, "default");
    default_.DataDownload(); // pay cost 1 time, of expensive 'operation'
    default_.Print();

    std::unique_ptr<Alien> superAlien = default_.Clone();
    superAlien->mData[0] = 9;
    superAlien->Print();

    return 0;
}