#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(){

	char c;
	while(read(STDIN_FILENO, &c, 1)==1 && c!= 'q'); //read and store user input in c mem addr
		
	return 0;
}
