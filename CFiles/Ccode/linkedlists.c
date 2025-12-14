#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
}nd;

// print linked list in rows of 5
void printlist(nd *head){
    nd *temp = head;
    int count =0;
    while(temp != NULL){
        printf("%d - ",temp->val);
        temp = temp->next;
        count +=1;
        if (count == 5){
            printf("\n");
            count = 0;
        }
    }
}

//create a new node in linked list
nd *creatend(int val){
    nd *x =malloc(sizeof(nd));
    x->val = val;
    x->prev = NULL;
    x->next = NULL;

    return x;
}

int main() {
    nd *head = NULL;
    int numvals;
    printf("\n\nhow many vaules in your list?\n >");
    scanf("%d",&numvals);
    
    for(int i = 0;i<numvals;i++){
        nd *x = creatend(i);
        x->next = head;
        head =x;
    }
    //prints in numbers 0 - numvals-1 in descending order

    printlist(head);
    return 0;
}