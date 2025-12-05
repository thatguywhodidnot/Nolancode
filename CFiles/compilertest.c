

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main(){
    FILE* file =  fopen ("nolanlanguage.nol", "r");
    
    char buffer[255];
    while (fgets(buffer, 255, file) != NULL){
    
        printf("%s", buffer);
    }


    fclose(file);
}
