
#include "header.h"

#define  width 32
#define  height 32

char field[height][width];

uint16 dot_x;
uint16 dot_y;

void clear_screen(){

	system("clear");

	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			field[i][j] = '_';
		}
	}

}

void print_field(){

	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			printf("%c",field[i][j]);
		}
		printf("\n");
	}


}

void print_dot(uint16 x, uint16 y){

	


}



int main(){

	clear_screen();
	print_field();
}
