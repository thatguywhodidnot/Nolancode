#include <iostream>





class Dog{
	//public attributes -> meaning they can be accessed form outside of class

	public:
	std::string breed;
	int age;

	//Constructors -> member functions that are auto called when and object of a class is made
	//will have the same name as class

	Dog(std::string b, int a){
	age = a;
	breed =b;
	}
};


int main(){

	double x = (5.11 % 1.0);

	std::cout << x<<"\n";

	return 0;
}




