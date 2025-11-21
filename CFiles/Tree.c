#include <stdio.h>
#include <stdlib.h>



typedef struct Treend
{
    int data;
    struct Treend* left;
    struct Treend* right;
}tnode;


tnode *mknode(int val){
    tnode *result = malloc(sizeof(tnode));
    if (result != NULL){
        result->data = val;
        result->left = NULL;
        result->right = NULL;

    
    }
    return result;
}

void levelformat(int level){
    for (int i = 0; i<level; i++){
        printf("\t");
    }

}

// level param added to format tree

void printtree(tnode*root, int level){
    if (root ==NULL){
        levelformat(level);
        printf("__empty__\n");
        return;

    }
    levelformat(level);
    printf("value = %d\n", root->data);
    levelformat(level);
    printf("left ");

    printtree(root->left,level+1);
    levelformat(level);
    printf("right ");

    printtree(root->right,level+1);

    levelformat(level);
}
int main(){

    tnode *root = mknode(110);
    tnode *l1 = mknode(100);
    tnode *l2 = mknode(10);
    tnode *l3 = mknode(1);
    tnode *r1 = mknode(200);
    // tnode *r2 = mknode(20);
    // tnode *r3 = mknode(2);

    root->left = l1; root->right = r1;
    l1->left = l2; l1->right = l3;

    printtree(root, 0);
    free(l2);free(l3);
    free(l1);free(r1);free(root);

    
    return 0;


}
