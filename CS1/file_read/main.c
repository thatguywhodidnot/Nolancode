#include <stdio.h>



int main(){

	FILE *fp, *ft;
	char word[100];


	fp = fopen("data.txt","r");
	fscanf(fp,"%s",word);
	rewind(fp);
	fscanf(fp,"%s",word);
	printf("%s", word);

	return 0;
}
