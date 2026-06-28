
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define TABLE_SIZE 50
#define PHY_ADDRS 30
#define MAX_INPUT 6
#define VALID_FREQUENCY 2


typedef struct frame{
    char* physical_addr;
    int data;
}frame;
typedef struct page{
    char* logical_addr;
    frame* match;
    bool valid;
}page;
//each page will hold a logical addr and a random integer as data
//there will be a list of logical address of size TABLE_SIZE
//there will be a list of physical addresses of size TABLE_SIZE/100

char* dec_to_bi(int decimal) {
    char temp[32];
    int i = 0;

    while (decimal > 0) {
        temp[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    char* binary = malloc((i + 1) * sizeof(char));

    for (int j = 0; j < i; j++) {
        binary[j] = temp[i - 1 - j];
    }

    binary[i] = '\0';

    return binary;
}


//a binary number as a string will be passed in
// convert that number to decimal then use that number as the index of page table if it is within range 1-50(1 = index 0, 50 = index 49)

int bin_to_dec(char* binary){
    char* endptr;
    return (strtol(binary, &endptr, 2)); 
}

int mmu_find(char* binary){
    if(strcmp(binary, "2") == 0){        
        return -2;
    }
    int decimal = bin_to_dec(binary);
    //printf("decimal conversion is %d\n", decimal);
    if(decimal>50 || decimal < 1){
        return -1;
    }
    else{
        return decimal-1;
    }

}

void mmu_check(page* page_table, int valid){
    
    if(valid != -1 && page_table[valid].valid == true){
        printf("\n%s is a valid logical address!\n", page_table[valid].logical_addr);
        printf("Matching Physical Address: \n %s\n", page_table[valid].match->physical_addr);
        printf("Data at Address: \n %d\n\n", page_table[valid].match->data);
    }
    else if(valid == -1){
        printf("\n\nAddress not in Page Table\n");
    }
    else if(page_table[valid].valid == false){
        printf("\n\nLogical address is Invalid\n");
    }
}

int main(){

    frame* physical_space = malloc(PHY_ADDRS*sizeof(frame));
    page* page_table = malloc(TABLE_SIZE*sizeof(page));
    srand(time(NULL));

    char input_addr[MAX_INPUT+1];
    int isvalid;
    bool run = true;
    //these for loops fill a randomly generated physical space of addresses and a randomly generated logical page table
    //uses binary versions of ints from 1 to TABLE_SIZE as addresses
    //randomly assigns each logical address to
    for(int i=0; i<PHY_ADDRS; i++){
        physical_space[i].physical_addr = dec_to_bi(i+1);
        physical_space[i].data = rand();
    }
    for(int i=0; i<(TABLE_SIZE); i++){   
        isvalid = rand() % VALID_FREQUENCY;
        if(isvalid >= 1){
            page_table[i].valid = true;    
        }
        else{
            page_table[i].valid = false;
        }
        page_table[i].logical_addr = dec_to_bi(i+1);
        if(page_table[i].valid == true){
            page_table[i].match = &physical_space[rand()%PHY_ADDRS];
        }
        
    }

    //read in logical address input to be checked by MMU
    while(run){

        printf("Input logical address as binary number of at most 6 digits\n");
        printf("Or enter '2' to leave\n>");
        scanf("%s", input_addr);
        
        int valid = mmu_find(input_addr);
        if(valid == -2){
            break;
        }
        mmu_check(page_table, valid);
    }


    for(int i = 0; i < PHY_ADDRS; i++){
    free(physical_space[i].physical_addr);
    }

    for(int i = 0; i < TABLE_SIZE; i++){
        free(page_table[i].logical_addr);
    }

    free(page_table); free(physical_space);

    return 0;
}