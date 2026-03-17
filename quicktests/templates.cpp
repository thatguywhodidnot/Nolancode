

#include <iostream>


//'X' is data type placeholder
//when function is called X can be something like a int OR a float
template <typename X>


X larger_val(X a,X b){

	return (a>b) ? a : b;
}


using namespace std;

int main(){
	cout << larger_val(34,37) << endl;
	cout << larger_val(34.6,37.5) << endl;
	return 0;
	
}
