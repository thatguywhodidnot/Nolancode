#include <stdio.h>

#include <stdlib.h>


typedef struct person{
	char* name;
	int age;
	struct person* next;
	struct person* prev;
}person;

int addperson(int len, char** arr ){

	len += 1;
	
	printf("enter person name: \n"); scanf("%6s", arr[len-1]);
	
	printf("person number %d is %6s\n", len, arr[len-1]);	

	return len;
}

person* addunique(int age, char* name){

	person *node = malloc(sizeof(node));
	node->name = name;
	node->age = age;
	node->next = NULL;
	node->prev = NULL;
	return node;
}



int main(){
	
	person *head = malloc(sizeof(head));
	head->next = NULL;
	head->prev = NULL;

	int ans;
	int len = 0;
	int unique_len = 0;
	char **namelist = malloc(5 * sizeof(char*));	
	for(int i=0;i<6;i++){
			namelist[i]=malloc(12*sizeof(char));
	}
	

	while(1){
			printf("what would you like to do?\n");
			if(len<1){
				printf("1 - add first person\n");
			}
			else{
				printf("1 - add person \n");
			}
			scanf("%d", &ans);

			//instead of if statement for each option in menu
			
			switch(ans){
			
				case 1:
						len = addperson(len, namelist);
						printf("%s", namelist[len-1]);
						break;
				case 2:
						;
						int age;
						char name[12];
						printf("enter person name: \n");scanf("%s", name);
						printf("enter person age: \n");scanf("%d", &age);
						person* node = addunique(age, name);
						
						if(head ==NULL){
							head=node;		
						}
						else{
								head->next = node;
								node->prev = head;
								head =node;
						}
						unique_len+=1;
						break;
						
				case 3:
					;
					person * tmp = head;
					while(tmp->prev != NULL){
						printf("%s is %d years old\n",tmp->name,tmp->age);
						tmp = tmp->prev;
					}
						break;
				case 4:
						return 0;
				default:
						break;
						
			}	
		}
	
}
