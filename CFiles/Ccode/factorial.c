
#include <stdio.h>



int factorial(int x){
	int count = x;
	int fact;
	for(int i=0; i<count-1; i++){
		x*=count-(i+1);
	}

	return x;
}




int main(){
	int x = 5;
	x = factorial(x);
	printf("%d",x);
	return 0;
}
