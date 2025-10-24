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

//I couldnt figure out how to do dma on scores arr with this format
} Player;

const char GAMES[NUMGAMES][MAXSIZE+1] = {"Wordle", "Spelling Bee",
"Crossword", "Connections", "Strands", "Letter Boxed", "Total"};

int compare(Player* ptrP1, Player* ptrP2, int key);
void mergeSort(Player** list, int n, int key);
void mergeSortRec(Player** list, int low, int high, int key);
void merge(Player **left, Player **right, Player **list, int n, int key);
int sum(int *arr,int n);

int main(void){
    int n,key;
    
    scanf("%d",&n);

    Player *playerlist = malloc(n* sizeof(Player));
    for(int i = 0; i<n; i++){
        playerlist[i].name = malloc(16*sizeof(char));
    }
    

    for(int i = 0; i<n; i++){
        scanf("%s",playerlist[i].name);
        for(int j= 0; j<TOTAL; j++){
            scanf("%d",&playerlist[i].scores[j]);
        }
        playerlist[i].scores[TOTAL]= sum(playerlist[i].scores,TOTAL);
    }
    scanf("%d",&key);

    Player **list = malloc(n*sizeof(*list));

    for(int i = 0; i<n; i++){
        list[i]=&playerlist[i];

    }
    
    mergeSort(list,n,key);
    

    
        

        
    printf("\n\n%s Ranklist\n",GAMES[key]);

    
    for(int i = 0; i<n; i++){
        int rank = i+1;
        printf("%d. %-15s %d\n", rank, list[i]->name,list[i]->scores[key]);
    }
    for(int i = 0; i<n; i++){
        free(playerlist[i].name);
    }
    free (playerlist);
    free(list);
}

int sum(int *arr,int n){
    int playersum = 0;
    for (int i = 0;i<n; i++){
        playersum+=arr[i];

    }
    return playersum;
}

void mergeSort(Player** list, int n, int key){
    if(n<=1){
        return;
    }
    //split passed array of structs 
    // will go recursively until arry is too small to sort
    //need to add 30 base cas
    int L_len = n/2;
    int R_len = n - L_len;
    Player **left = malloc(L_len * sizeof(Player));
    Player **right = malloc(R_len * sizeof(Player));
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
    //at the end of rcursion all split arrays merge back
    merge(left,right,list, n,key);


    free(left);
    free(right);

}
void merge(Player **left, Player **right, Player **list, int n,int key){
    int L_len = n/2;
    int R_len = n - L_len;
    int i=0,R=0,L= 0;

    //going thru left and right arrays, add to list based on values size rel to each other
    while(L<L_len && R<R_len){
        if (compare(left[L],right[R],key) == 1){
            list[i] = left[L];
            i++; L++;

        }
        else {
            list[i] = right[R];
            i++; R++;
        }
    }
    while(L<L_len){
        list[i] = left[L];
            i++; L++;
    }
    while(R<R_len){
        list[i] = right[R];
            i++; R++;
    }
}


//will replace if statement in merge
int compare(Player* ptrP1, Player* ptrP2, int key){
    if (ptrP1->scores[key]< ptrP2->scores[key]){
            return 0;
        }
    else{
        return 1;
    }
}
//will call for 30 base case
void mergeSortRec(Player** list, int low, int high, int key){

    compare(list[low],list[high],key);

}