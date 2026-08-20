#include<iostream>
#include<vector>
#include<string>

class Logger{
    public:
   /*
   Retrieve the single instance of the object
   created, and we will enforce only 1 of these
   objects gets created in our code logic
   */
    static Logger& GetInstance(){
        static Logger* s_instance = new Logger;

        return *s_instance;
   }
   
    void printMessages(){
        std::cout<<"Accessing the log"<<std::endl;
        for(auto e: m_messages){
            std::cout<<e<<std::endl;
        }
    }

    void addMessage(std::string s){
            m_messages.push_back(s);
    }

    private:
    Logger(){
        std::cout<<"Logger was created\n";
    }
    ~Logger(){
        std::cout<<"Logger was destructed\n";
    }

    std::vector<std::string> m_messages;
};


int main(){    
    Logger::GetInstance().addMessage("Hello Message 1");
    Logger::GetInstance().addMessage("Hello Message 2");
    Logger::GetInstance().addMessage("Hello Message 3");
    Logger::GetInstance().printMessages();
    return 0; 
}
