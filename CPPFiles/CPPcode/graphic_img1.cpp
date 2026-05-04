
#include <iostream>



namespace one{ int x =1; };
namespace two{ int x =4;};

int main(){ 
    using namespace one;
    
    std::cout<< x; 

    return 0;
};