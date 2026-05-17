



#include <stdio.h>
#include <stdlib.h>

typedef struct your_struct{
	int your_int;
	char *your_string; 
}your_struct;

int main(){
	
	int rows = 3, columns = 3, string_size = 10;
	

	//malloc a 2d array example
	//the first line allocates 'rows' amoount of 'yourstruct' pointers
	//the for loop allocates data for a struct using the previously allocated pointers 
	
	//only the last of your allocation loop actualy allocates the struct data.
	//the rest of the lines will be pointers to where the structdata is
	//whenever you write arr[number] that is a pointer

	//for use copy malloc for loops into you array making function and return arr

	your_struct **arr = malloc(rows*sizeof(your_struct*));


	for(int i = 0; i < rows; i++){
		arr[i] = malloc(columns*sizeof(your_struct));

		for(int j = 0; j < columns; j++){
			arr[i][j].your_string = malloc(string_size*sizeof(char));
		}
			
	}
	for(int i = 0; i < rows; i++){

		for(int j = 0; j < columns; j++){

				for(int k = 0; k < string_size; k++){
					arr[i][j].your_string[k] = 'a' + (rand()%10);
			}

		}
			
	}
	for(int i = 0; i < rows; i++){
	
		for(int j = 0; j < columns; j++){
			
			printf("%s ", arr[i][j].your_string);

		}
			
		printf("\n");

	}
	for(int i = 0; i < rows; i++){

		for(int j = 0; j < columns; j++){
			
			free(arr[i][j].your_string);
		}
			
		free(arr[i]);
	}
	free(arr);

}
