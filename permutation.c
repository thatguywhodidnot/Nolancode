#include <stdlib.h>
#include <stdio.h>

void swap(char *x, char *y){
    
    char temp = *x;
    *x = *y;
    *y = temp;
}

void perm(char *word, int start, int end){
    int i;
    if(start == end ){
        printf("%s \n",word);

    }
    else {
        
        for (i = start; i <= end; i++) {
        
            swap((word + start), (word + i));

            perm(word, start + 1, end);

            swap((word + start), (word + i));
        }
    }
}





int main() {
    int wordlen;
    
    
    printf("how many letters in your perm? \n>");
    scanf("%d",&wordlen);



    printf("give the letters in your perm \n>");
    char *letters = malloc(wordlen*sizeof(char)) ;
    scanf("%s", letters);
    
    perm(letters, 0 , wordlen-1);
    

    return 0;
}