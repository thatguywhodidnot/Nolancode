
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

void print_dot(float spinx, float spiny, char draw){
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			float y = abs(i-diam);
			float x = j;
			float xshift = (pow(spinx*(x-rad),2.0));
			float yshift = (pow(spiny*(y-rad),2.0));
			float pointval = xshift +yshift;
			if(isaround(pointval,pow(rad,2.0))==0){
				field[i][j] = draw;
				//printf("made point at (%f , %f)",x,y);
			}
		}
	}
	print_field();
}

void rotate_dot(char draw){
	float turn_rate = 1/frames;
	for(float i=1; i<full; i+=turn_rate){
		i+=i/2.0;
		clear_screen();
		print_dot(i,1,draw);
		print_dot(1,i,'o');
		usleep(frame_space);

	}	

	for(float i=full; i>1; i-=turn_rate){
		i-=i/2.0;
		clear_screen();
		print_dot(i,1,draw);
		print_dot(1,i,'o');
		usleep(frame_space);
	}
}

void print_static(){
	float circle_width, circle_height;
	printf("circle width \n>");
	scanf("%f",&circle_width);
	printf("circle height \n>");
	scanf("%f",&circle_height);
	clear_screen();
	print_dot(circle_width,circle_height,'1');

}

void spin_for(int rotations){
	for(int i=0; i<rotations; i++){
		clear_screen();
		rotate_dot('1');
		
	}
}

int main(){
	spin_for(20);
	//print_static();
}
