#include <stdio.h>
#include <stdlib.h>


typedef struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
}treenode;

treenode *createnode(int data);
void printtree(treenode *root);


treenode * createnode(int data){
    if(0 == data){
        return 0;
    }
    treenode *node = malloc(sizeof(node));
    node->data = data;
    int rdata, ldata;

    printf("what is the right child of %d?",data);
    scanf("%d",&rdata);
    printf("what is the left child of %d?",data);
    scanf("%d",&ldata);
    if(0 == rdata && 0 == ldata){
        return node;
    }
    
    node->right = createnode(rdata);
    node->left = createnode(ldata);
    return node;
    
}

void printtree(treenode *root){
    if(root == NULL){
        return;
    }
    printf("%d\n", root->data);
    printtree(root->left);
    
    printtree(root->right);
}



int main(){
    int root;
    printf("give your root val \n");
    scanf("%d", &root);
    printtree(createnode(root));





    return 0;
}