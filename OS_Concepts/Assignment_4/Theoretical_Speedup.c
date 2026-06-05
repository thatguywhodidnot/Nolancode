#include <stdio.h>

void S_calc(int q_num){

	float S, P, N;
	printf("enter question %d P and N values( P N ):\n", q_num);
	scanf("%f %f", &P, &N);
	S = 1/((1 - P) + (P/N));
	printf("Question %d Theoretical speed up is:\n %.2f\n\n", q_num, S);
	
}

int main(){
	int i, questions;
	
	printf("how many Amdahl's Law calculations are being done?\n>");
	scanf("%d", &questions);
	for(i=0; i<questions; i++){
		S_calc(i+1);
	}


	return 0;
}




