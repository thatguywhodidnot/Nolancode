
#include <iostream>
#include <string>
#include <cmath>



class client{
    public:
        client(std::string name ){
            std::cout << name << " has arisen\n";
        };
};

class old_client : public client{

    public:
        
        //using the 'client' constructor from the parent class 'client' 
        using client::client;

        void time_spent(int years){
            std::cout << years << std::endl;
        };


};

int main(){
    // using namespace std;
    auto x = sin(90);
    std::cout<<x<<std::endl;
    
   

    // old_client saggy_sack("oldie");


    // client ball_sack("ball sack");

    return 0;
};