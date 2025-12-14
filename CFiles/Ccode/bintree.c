#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
}treenode;

treenode *createnode(int data);



treenode * createnode(int data){
    if(0 == data){
        return 0;
    }
    treenode *node = malloc(sizeof(treenode));
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    int rdata, ldata;

    printf("what is the right child of %d?",data);
    scanf("%d",&rdata);
    printf("what is the left child of %d?",data);
    scanf("%d",&ldata);
    if(0== rdata && 0== ldata){
        return node;
    }
    
    node->right = createnode(rdata);

    node->left = createnode(ldata);
    return node;
    
}

void printtree(treenode *root,char *side, int parent){
    if(root == NULL)return;
    if(strcmp(side,"M")==0)printf("Root = %d\n", root->data);
    else printf("%s child of %d is %d\n",side,parent,root->data);
    

    printtree(root->left, "L", root->data);
    printtree(root->right, "R", root->data);
    return;
}



int main(){
    int root;
    printf("give your root val \n");
    scanf("%d", &root);
    printtree(createnode(root), "M",0 );





    return 0;
}