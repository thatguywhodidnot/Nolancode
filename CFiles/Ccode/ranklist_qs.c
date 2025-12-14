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
int partition(Player **list,int low,int high, int key);

int sum(int *arr,int n);

int main(void){
    int n,key;
    
    scanf("%d",&n);

    Player *list = malloc(n* sizeof(*list));
    Player **playerlist = malloc(n* sizeof(*playerlist));
    

    for(int i = 0; i<n; i++){
        list[i].name = malloc(15 * sizeof(char));
        // for (int j =0; j<NUMGAMES;j++){
        //     playerlist[i].scores = malloc(NUMGAMES*sizeof(int));
        // }
        //playerlist[i]->scores = malloc(NUMGAMES*sizeof(int));
    }
    for(int i = 0; i<n; i++){
        scanf("%s",list[i].name);
        for(int j= 0; j<TOTAL; j++){
            scanf("%d",&list[i].scores[j]);
            
        }
        list[i].scores[TOTAL]= sum(list[i].scores,TOTAL);
    }
    scanf("%d",&key);

    for(int i = 0; i<n; i++){
        playerlist[i]=&list[i];

    }
    
    quickSortRec(playerlist, 0, n-1, key);
    

    /*
    for(int i = 0; i<n; i++){

    printf("%d. %-15s %d\n", rank, name, score);
    }
    */
   
    printf("\n\n%s Ranklist\n",GAMES[key]);

    for(int i = n-1; i!=0; i--){
        int rank = i+1;
        printf("%d. %-15s %d\n", rank, playerlist[i]->name,playerlist[i]->scores[key]);
    }


    for(int i = 0; i<n; i++){
        free(playerlist[i]->name);
        
    }
    free (playerlist);
}


int sum(int *arr,int n){
    int playersum = 0;
    for (int i = 0;i<n; i++){
        playersum+=arr[i];

    }
    return playersum;
}

int median(int one, int two, int three){
    if(one<two && one>three || one>two && one<three){
        return one;
    }
    else if(one>two && one<three || one<two && two<three){
        return two;
    }
    else{
        return three;
    }
}

void quickSort(Player** list, int n, int key){

}
void quickSortRec(Player** list, int low, int high, int key){
    if (low >= high){
        return;
    }
    int pivot = partition(list,low,high,key);
    quickSortRec(list, low, pivot -1, key);
    quickSortRec(list, pivot+1, high, key);

}   

int compare(Player* ptrP1, Player* ptrP2, int key){
    if (ptrP1->scores[key]< ptrP2->scores[key]){
            return 0;
        }
    else{
        return 1;
    }
    }
    



int partition(Player **list, int low, int high,int key){
    int small = list[low]->scores[key];
    int big = list[high]->scores[key];
    int avg = (small+big)/2;
    int pivot = median(small, big, avg);
    Player* pivotplayer = list[0];
    pivotplayer->scores[key] = pivot;
    int i = low - 1;
    for (int j = low; j< high; j++){
        if (compare(list[j],pivotplayer, key) == 0){
            i++;
            Player* temp = list[i];
            list[i] = list[j];
            list[j] = temp;

        }

        // if (list[j]->scores[key]< pivotplayer->scores[key]){
            // i++;
            // Player* temp = list[i];
            // list[i] = list[j];
            // list[j] = temp;
        // }
    }
    //catch values not sorted in fo
    i++;
    Player* temp = list[i];
    list[i] = list[high];
    list[high] = temp;
    return i;
}