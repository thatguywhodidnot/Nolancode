#include <iostream>



class Man{
		public:
				//adding virtual to make it a virtual function allow for the same function in the child classes to do different things
				
				virtual void talk(){
					std::cout << "Hello I am man" << std::endl;
				}
				void walk(){
					std::cout << "A man is walking" << std::endl;

				}

};

class Woman : public Man{
	public :
			//instead of the talk function in Woman pointing to the Man talk function it does its own thing 
			void talk(){
				std::cout << "Hello i am Woman" << std::endl;
			}

			void walk(){
				std::cout << "A woman is walking" << std::endl;
			}
	

};


int main (){
	

	//yaderi is a pointer with the type of Man. but the man pointer is pointing to the woman class
	//because the pointer type is man you can only call functions within both man and woman
	//the woman function you call does not match with a VIRTUAL man function but instead matches with a regular function in man it will use the man function
	//virtual function is needed for proper smart calling 
	Man * yaderi = new Woman;
	yaderi -> talk();
	yaderi -> walk();

}
//virtual function overhead
//single calls are cheap but dont use too many
//ex:
//
//shape class has area function that needs to be virtual because calculating are for circle child clas will be different than for square child class
//shap class and its children might have a color function that does not need to be changed for the children and so should not be virtual because it is unnecessary overhead


