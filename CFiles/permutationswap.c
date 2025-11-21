#include <stdlib.h>
#include <stdio.h>


char **used;
int wordcount=0;




void swap(char *x, char *y){
    
    char temp = *x;
    *x = *y;
    *y = temp;
}

int checkused(char *word){
    for(int i=0; i<wordcount; i++ ){
        if (word == used[i]){
            return 1;
        }

    }
    return 0;
}




void perm(char *word, int start, int end){
    int i;
    if(start == end && checkused(word)== 0){
        
        used[wordcount] = word;
        wordcount +=1;
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
    char *letters = malloc((wordlen+1)*sizeof(char)) ;
    scanf("%s", letters);
    
    perm(letters, 0 , wordlen-1);
    

    return 0;
}