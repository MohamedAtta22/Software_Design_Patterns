#include<vector>
#include<iostream>
#include<unordered_map>

int main(){
    std::vector<int> ints = {0,1,2,3,4,5,6,7,8,9};

    std::cout<<"Iterator"<<std::endl;
    for(std::vector<int>::iterator it = ints.begin(); it != ints.end(); ++it){
        std::cout<< *it<<",";
    }

    std::cout<<"Const Iterator"<<std::endl;
    for(std::vector<int>::const_iterator it = ints.cbegin(); it != ints.cend(); ++it){
        std::cout<< *it <<",";
    }
    // (*it)++ // illegal for us to modufy element
    std::cout<<std::endl<<std::endl;

    std::cout<<"Reverse Iterator"<<std::endl;
    for(std::vector<int>::reverse_iterator it = ints.rbegin(); it != ints.rend(); ++it){
        std::cout<< *it <<",";
    }
    std::cout<<std::endl<<std::endl;

    // more familiar to 'java' style
    std::cout<<"Controlling advancing of Iterators"<<std::endl;
    auto it = ints.begin(); 
    // equivalent to 
    // std::vector<int>::iterator it = ints.begin();
    while(it != ints.end()){
        auto element = std::next(it, 0); // Return element at current position
                                        // 1 would give us the next element                                                    
                                        // 2 would give us 2 elements later
                                        // etc
        std::cout<< *element<<",";      // Display to the user
        std::cout<< *it <<",";
        std::advance(it, 1); // equivalent to it++
    }
    std::cout<<std::endl<<std::endl;

    // range-based loops in c++11 and beyond
    // able to do this because of iterators
    std::cout<<"Range-based for loops"<<std::endl;
    for(const auto e : ints){
        // Note: you can use 'int e' instead since we know the element
        //       for larger objects. I recommend `const auto& e`
        std::cout<<e<<" ";
    }
    std::cout<<std::endl<<std::endl;


    std::cout<< "unordered_map iterator example"<<std::endl;
    // create a less trivial data structure
    // where we don't have random-access
    std::unordered_map<std::string, int> people;
    // add a few people to our map with keys of 'string' and values of 'int'
    people["Person1"]=444;
    people["Person2"]=555;
    using peopleiterator = std::unordered_map<std::string, int>::iterator;
    for(peopleiterator it2 = people.begin(); it2 != people.end(); it2++){
        std::cout<<it2->first<<" - "<<it2->second<<std::endl;
    }


    return 0;
}