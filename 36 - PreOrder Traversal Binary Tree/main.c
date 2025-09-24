#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

/*
        4
       / \
      1   6
     / \
    5   2

Pre order: Root Left Right
Pre order: 4 1 5 2 6
*/

void preOrder(struct Node *root){ // This is one of the problems recursion gives an elegant solution to
    printf("%d ", root->data);
    if(root->left!=NULL){
        preOrder(root->left);
    }
    if(root->right!=NULL){
        preOrder(root->right);
    }
}

void init(struct Node **node, int data){
    *node = (struct Node *) malloc(sizeof(struct Node));
    (*node)->data = data;
    (*node)->left = NULL;
    (*node)->right = NULL;
}


int main()
{
    struct Node *root, *child1, *child2, *grandChild1, *grandChild2;
    init(&root, 4);
    init(&child1, 1);
    init(&child2, 6);
    init(&grandChild1, 5);
    init(&grandChild2, 2);

    root->left = child1;
    root->right = child2;

    child1->left = grandChild1;
    child1->right = grandChild2;

    printf("Pre Order Traversal: ");
    preOrder(root);



    return 0;
}
