#include <stdio.h>
#include <stdlib.h>
//Nolan Milligan


typedef struct dllnode {
    char ch;
    struct dllnode* prev;
    struct dllnode* next;
} dllnode;



dllnode *createl(char ch){
    dllnode *n = malloc(sizeof *n);
    n->ch = ch;
    n->next =NULL;
    n->prev = NULL;
    return n;
}

void printdll(dllnode *head){
    dllnode * temp = head;
    while(temp !=NULL){
        printf("%c",temp->ch);
        temp = temp->next;
        
    }
    
}

dllnode *strandone(char **lvals, int **nvals, int **pvals, int numRows, int numCols, int r, int c){
    
    int NUMDIR = 8;
    const int NULLPTR = -1;
    const int DR[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int DC[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    while(pvals[r][c]!= NULLPTR){
        r+=DR[pvals[r][c]];
        c+=DC[pvals[r][c]];
        
        
    }
    
    dllnode *head = createl(lvals[r][c]);
    dllnode *tail = head;

    while(nvals[r][c]!= -1){
        int x = nvals[r][c];
        r+=DR[x];
        c+=DC[x];
        dllnode *node = createl(lvals[r][c]);
        tail->next = node;
        node->prev = tail;
        tail = node;
        
    }
    printdll(head);
}
dllnode *strandtwo(char **lvals, int **nvals, int **pvals, int numRows, int numCols, int r, int c){
    
    int NUMDIR = 8;
    const int NULLPTR = -1;
    const int DR[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int DC[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    while(pvals[r][c]!= -1){
        r+=DR[pvals[r][c]];
        c+=DC[pvals[r][c]];
        
        
    }
    
    dllnode *head = createl(lvals[r][c]);
    dllnode *tail = head;

    while(nvals[r][c]!= -1){
        int x = nvals[r][c];
        r+=DR[x];
        c+=DC[x];
        dllnode *node = createl(lvals[r][c]);
        tail->next = node;
        node->prev = tail;
        tail = node;
        
    }
    dllnode *cur = head, *tmp = NULL;
    while (cur!=NULL) {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev;
    }
    head = tmp->prev;
    printdll(head);
}

dllnode *strandthree(char **lvals, int **nvals, int **pvals, int numRows, int numCols, int r1, int c1, int r2, int c2){
    int NUMDIR = 8;
    const int DR[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int DC[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    while (pvals[r1][c1] != -1) {
        int d = pvals[r1][c1];
        r1 += DR[d];
        c1 += DC[d];
    }
    
    dllnode *h1 = createl(lvals[r1][c1]);
    dllnode *t1 = h1;
    
    while (nvals[r1][c1] != -1) {
        int d = nvals[r1][c1];
        r1 += DR[d];
        c1 += DC[d];
        dllnode *node = createl(lvals[r1][c1]);
        t1->next = node; 
        node->prev = t1; 
        t1 = node;
    }

    while (pvals[r2][c2] != -1) {
        int d = pvals[r2][c2];
        r2 += DR[d];
        c2 += DC[d];
    }
    /
    dllnode *h2 = createl(lvals[r2][c2]);
    dllnode *t2 = h2;
    r2 = r2; c2 = c2;
    while (nvals[r2][c2] != -1) {
        int d = nvals[r2][c2];
        r2 += DR[d];
        c2 += DC[d];
        dllnode *node = createl(lvals[r2][c2]);
        t2->next = node; 
        node->prev = t2; 
        t2 = node;
    }

    
    printdll(h1);
    printdll(h2);
}






int main() {
    
    int numRows;
    int numCols;
    int numQues;
    dllnode*** strandsGrid;
    
    scanf("%d %d",&numRows,&numCols);
    
    
    char **lvals = malloc(numRows*sizeof *lvals);
   
    
    for(int i= 0; i<numRows; i++){
        lvals[i] = malloc((numCols)*sizeof *lvals[i]);
        
        for(int j= 0; j<numCols; j++){
            scanf(" %c", &lvals[i][j]);
        }
    }
    
 
    
    int **nvals = malloc(numRows* sizeof *nvals);
    for(int i= 0; i<numRows; i++){
        nvals[i] = malloc(numCols*sizeof *nvals[i]);
        for(int j= 0; j<numCols; j++){
            scanf(" %d",&nvals[i][j]);
            
        }
    }
    //scan for prev vals
    int **pvals = malloc(numRows* sizeof *pvals);
    for(int i= 0; i<numRows; i++){
        pvals[i] = malloc(numCols*sizeof *pvals[i]);
        for(int j= 0; j<numCols; j++){
            scanf(" %d",&pvals[i][j]);
            
        }
    }
    
    //scan for query types
    scanf("%d",&numQues);
    int **Queries = malloc(numQues* sizeof *Queries);
    int *qtype = malloc(numQues* sizeof(int));
    
    for(int i= 0; i<numQues; i++){
        scanf("%d",&qtype[i]);
        if(qtype[i] == 1||qtype[i] ==2){
            Queries[i] = malloc(2*sizeof *Queries[i]);
            
            for(int j= 0; j<2; j++){
            scanf(" %d",&Queries[i][j]);
            }
            
        }
        else if(qtype[i] ==3){
            Queries[i] = malloc(4*sizeof *Queries[i]);
            
            for(int j= 0; j<4; j++){
            scanf(" %d",&Queries[i][j]);
            }
        
        }
    
    }
    for(int i= 0; i<numQues; i++){
        if (qtype[i] == 1){
                dllnode *strand = strandone(lvals,nvals,pvals, numRows,numCols,Queries[i][0],Queries[i][1]);
                printf("\n");
            }
        if (qtype[i] == 2){
                dllnode *strand = strandtwo(lvals,nvals,pvals, numRows,numCols,Queries[i][0],Queries[i][1]);
                printf("\n");
            }
        else if ( qtype[i] ==3){
            
                
                
            dllnode *first = strandthree(lvals,nvals,pvals, numRows,numCols,Queries[i][0],Queries[i][1],Queries[i][2],Queries[i][3]);
            
            printf("\n");
            
        }
        
       
    }

    
   
    

    for(int i= 0; i<numRows; i++){
        free(nvals[i]);
        free(lvals[i]);
        free(pvals[i]);
    }
    free(nvals);
    free(lvals);
    free(pvals);

    return 0;
}
