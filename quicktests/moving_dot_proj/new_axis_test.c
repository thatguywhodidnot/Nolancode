

#define  xchar 'o'
#define  ychar 'l'
#define  x_slant_char '_'
#define  y_slant_char '3'
#include "header.h"
#include "dot_variables.h"

char field[height][width];

void clear_screen(){

	system("clear");

	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			field[i][j] = ' ';
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
//chack if x is close to y
int isaround(float x,float y){
		
		if(abs(x-y)<tol){
			return 0;
		}
		else if(abs(y-x)<tol){
			return 0;
		}
		else{ 
			return 1;
		}
}

void print_dot_slant(float spinx, float spiny, char draw){
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			float y = (abs(i-diam))-center_ypos;
			float x = j - center_xpos;
			x = x_slant_condense*x;
			y = y_slant_condense*y;
			float xshift = spinx*(pow((x+y),2.0));
			float yshift = spiny*(pow((x-y),2.0));
			float pointval = xshift +yshift;
			if(isaround(pointval,pow(rad,2.0))==0){
				field[i][j] = draw;
				//printf("made point at (%f , %f)",x,y);
			}
		}
	}
	print_field();
}

void print_dot(float spinx, float spiny, char draw){
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			float y = abs(i-diam);
			float x = j;
			x = x_condense*x;
			y = y_condense*y;
			float xshift = (pow(spinx*(x-center_xpos),2.0));
			float yshift = (pow((spiny*2)*(y-center_ypos),2.0));
			float pointval = xshift +yshift;
			if(isaround(pointval,pow(rad,2.0))==0){
				field[i][j] = draw;
				//printf("made point at (%f , %f)",x,y);
			}
		}
	}
	print_field();
}


void rotate_dot(){
	float turn_rate = 1/frames;
	for(float i=1; i<full; i+=turn_rate){
		i+=i/turn_exp;
		clear_screen();
		print_dot_slant(i,1,xchar);
		print_dot_slant(1,i,ychar);
		print_dot(i,1,x_slant_char);
		print_dot(1,i,y_slant_char);
	
		usleep(frame_space);

	}	

	for(float i=full; i>1; i-=turn_rate){
		i-=i/turn_exp;
		clear_screen();
		print_dot_slant(i,1,xchar);
		print_dot_slant(1,i,ychar);
		print_dot(i,1,x_slant_char);
		print_dot(1,i,y_slant_char);
	
		usleep(frame_space);
	}
}

void spin_for(int rotations){
	if(rotations == 0){
		int spin =0;
		while(spin == 0){
			clear_screen();
			rotate_dot();
		}
	}

	else{
		for(int i=0; i<rotations; i++){
			clear_screen();
			rotate_dot();
		}
	}
	
}

int main(){
	spin_for(0);	


}
