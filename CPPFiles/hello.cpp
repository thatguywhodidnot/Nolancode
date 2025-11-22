
// first cpp program for general knowledge stuff coming from c


#include <iomanip>
#include <string>
// iostream is cpp friendly in and out
#include <iostream>
// cstdio, cstd___ headers are for the c style functions
// good for basic stuff but wont work with cpp new non c features like OOP
#include <cstdio>

//glew has all the functions you need glewInit() to us modern GL functions
#include <GL/glew.h

//glad is more modern than glew
#include <glad/glad.h>
//glfw is for windows and input 
#include<GLFW/glfw3.h>



void print_c_cpp(int x){
    printf("hello\n using printf from cstdio\n\n"); // from cstdio C style


    std::cout <<"hello\n using cpp iostream\n\n"; // from iostream C++
    // do variables with std::cout <<"words"<<variable<<"words";
    std::cout <<"variable printing example line "<<x<<" words\n\n";


}


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


int main(){
    int x = 2025;
    //proper mem allocation
    std::string* centwords = new std::string[4];
    delete[] centwords;



    return 0;
}
