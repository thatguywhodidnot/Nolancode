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
} Player;

const char GAMES[NUMGAMES][MAXSIZE+1] = {"Wordle", "Spelling Bee",
"Crossword", "Connections", "Strands", "Letter Boxed", "Total"};

int compare(Player* ptrP1, Player* ptrP2, int key);
void quickSort(Player** list, int n, int key);
void quickSortRec(Player** list, int low, int high, int key);

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