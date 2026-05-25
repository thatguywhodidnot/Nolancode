/* main.c | Nolan Milligan */

#include <stdio.h>

//this code reads a word given when the executable file is run into the array of strings 'your_name'
//the name you give is stored in index 1 and index 0 is the name of the .out file
//the terminal above shows how I compiled the code with gcc ran the created a.out file with my name(Nolan), and got the output "Hello world my name is Nolan"

int main(int args, char **your_name){

	printf("Hello world my name is %s\n\n", your_name[1]);
	
	return 0;
}



