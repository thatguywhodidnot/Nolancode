

/* comment out
multilines 
Big balls */

#include <cstdio>
#include <iostream>
#include <string>

void center_out(const std::string&str, int width, char fill ){
    int totalfill = (width - str.size());
    int pad = totalfill/2;
    if (pad<0)pad=0;

    
    std::cout
        << std::string(pad, fill)
        << " " << str << " "
        << std::string(totalfill-pad, fill)
        << "\n";
}

class client{
    public:
        std::string id;
        std::string name;
    
        
};

int main()
{

    int width = 100;
    int lpad = 35;

    std::cout << "\n"; center_out("WELCOME TO BANKING SYSTEM!", width , ' ');std::cout << "\n"; 
    center_out("MENU", width, ' '); center_out(std::string(30, '-'), width, ' ');
    // center_out("OPTIONS",20, ' ');std::cout << "\n";
    std::cout << std::string(lpad, ' ')<<"OPTIONS\n";

    for(int i =0; i<5;i++){
        
        std::cout << std::string(lpad, ' ') << i+1 << ". - \n";
    }

}

