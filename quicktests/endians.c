
//endians big and little are for different ways to store data types with multiple bytes
//ints, floats, arrays are multibytes data types
//how they are stored depends on the endian
//one  endian is not inherently more effiecient than the other




#include <stdio.h> 
#include <stdlib.h> 


//the order in which variables are defined in t a program matters as well 
//integers are 4 bytes long and can only start in byte multiples of 4 in the memory struct A makes up
//struct a   = 0 1 2 3 4 5 6 7
//int first: = a a a a b c _ _
//int second = b _ _ _ a a a a c _ _ _
//blank spaces are padding and struct a must have a byte count that is a multiple of 4
//save memory and speed up program by making sure multibyte and singlebyte data types are organized in memory space


struct A {
	int a;
	char b;
	char c;

};//size == 8 bytes

struct B{
	char a;
	int b;
	char c;

};// size == 12 bytes


int main(){
	int bytes = 4;
	
	
	int* multiB = malloc(bytes* sizeof(int));
	

	printf("struct A size : %zu\n", sizeof(struct A));	
	printf("struct B size : %zu\n", sizeof(struct B));	

	
	

	free(multiB);



}




