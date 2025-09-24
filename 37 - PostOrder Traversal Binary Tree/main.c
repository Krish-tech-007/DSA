#include <stdio.h>
#include <stdlib.h>


/*
        4
       / \
      1   6
     / \
    5   2

Post Order: Left Right Root
Post Order: 5 2 1 6 4
*/

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

void init(struct Node **node, int data){
    *node = (struct Node *) malloc(sizeof(struct Node));
    (*node)->data = data;
    (*node)->left = NULL;
    (*node)->right = NULL;
}

void postOrder(struct Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root, *c1, *c2, *gc1, *gc2;
    init(&root, 4);
    init(&c1, 1);
    init(&c2, 6);
    init(&gc1, 5);
    init(&gc2, 2);

    root->left = c1;
    root->right = c2;
    c1->left = gc1;
    c1->right = gc2;

    printf("Post Order: ");
    postOrder(root);
    return 0;
}
