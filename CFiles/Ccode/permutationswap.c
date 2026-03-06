#include <stdio.h>
#include <string.h>

//char permlist [][];
int count = 0;

void swap (char *one, char *two){
    char tmp = *one;
    *one = *two;
    *two = tmp;

}

void permutate(int x, char *word, int len){
    if (x ==1){
        count +=1;

        printf("%.*s - %d \n",len, word, count);
        
        return;
    }
    
    else{
        for (int i= 0; i<x; i++){
            
            permutate(x-1, word, len);

            if(x%2 == 0 ){
                swap(&word[i], &word[x-1]);
            }
            else{            
                swap(&word[0], &word[x-1]);
            }
        }
        
    }
}

int main() {
    char word [] = "Nolan";
    int x = (int)strlen(word);
    permutate(x,word,x);

    return 0;
}