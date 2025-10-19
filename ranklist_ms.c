//solution with merge sort
#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 12
#define NUMGAMES 7
#define TOTAL 6
#define BASECASESIZE 30



typedef struct Player {
char* name;
int scores[NUMGAMES];
//why not 'int *scores;' ?
//I couldnt figure out how to do dma on scores arr with this format
} Player;

const char GAMES[NUMGAMES][MAXSIZE+1] = {"Wordle", "Spelling Bee",
"Crossword", "Connections", "Strands", "Letter Boxed", "Total"};

int compare(Player* ptrP1, Player* ptrP2, int key);
void mergeSort(Player** list, int n, int key);
void mergeSortRec(Player** list, int low, int high, int key);
void merge(Player **left, Player **right, Player **arr, int arrlen);

int main(void){
    int n,key;
    
    scanf("%d",&n);

    Player *playerlist = malloc(n* sizeof(Player));

    for(int i = 0; i<n; i++){
        playerlist[i].name = malloc(15 * sizeof(char));
        //playerlist[i].scores = malloc(NUMGAMES*sizeof(int));
    }

    for(int i = 0; i<n; i++){
        scanf("%s",playerlist[i].name);
        for(int j= 0; j<TOTAL; j++){
            scanf("%d",&playerlist[i].scores[j]);
        }
    }
    scanf("%d",&key);

    /*
    for(int i = 0; i<n; i++){

    printf("%d. %-15s %d\n", rank, name, score);
    }
    */

    printf("\n\n%s Ranklist\n\n",GAMES[key]);


    for(int i = 0; i<n; i++){
        free(playerlist[i].name);
        
    }
    free (playerlist);
}

void mergeSort(Player** list, int n, int key){
    if(n<=1){
        return;
    }
    int L_len = n/2;
    int R_len = n - L_len;
    Player **left = malloc(L_len * sizeof(int));
    Player **right = malloc(R_len * sizeof(int));
    for(int i =0; i<L_len; i++){
        if (i< L_len){
            left[i] = list[i];

        }
    }
    for(int i =0; i<R_len; i++){
        if (i< R_len){
            right[i] = list[L_len+i];

        }
    
    }
    mergeSort(left, L_len, key);
    mergeSort(right,R_len, key);
    merge(left,right,list, key);

}
void merge(Player **left, Player **right, Player **arr, int arrlen){
    int L_len = arrlen/2;
    int R_len = arrlen - L_len;
    int i=0,R=0,L= 0;

    while(L<L_len && R<R_len){
        if (left[L]<right[R]){
            arr[i] = left[L];
            i++; L++;

        }
        else {
            arr[i] = right[R];
            i++; R++;
        }
    }
    while(L<L_len){
        arr[i] = left[L];
            i++; L++;
    }
    while(R<R_len){
        arr[i] = right[R];
            i++; R++;
    }
}
int compare(Player* ptrP1, Player* ptrP2, int key){
    return 0;
}

void mergeSortRec(Player** list, int low, int high, int key){

    compare(list[low],list[high],key);

}