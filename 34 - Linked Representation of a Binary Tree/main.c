#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Linked Representation
struct Node { // Self referential structure
    int data;
    struct Node *left;
    struct Node *right;
};

void init(struct Node *node, int data){
    node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}
int main()
{
    // Constructing the root node
    struct Node *root = (struct Node *) malloc(sizeof(struct Node));
    root->data = 0;
    root->left = NULL;
    root->right = NULL;

    // Constructing child nodes
    struct Node *rootLeftChild = (struct Node *) malloc(sizeof(struct Node));
    rootLeftChild->data = 1;
    rootLeftChild->left = NULL;
    rootLeftChild->right = NULL;

    struct Node *rootRightChild = (struct Node *) malloc(sizeof(struct Node));
    root->rightChild->data = 2;
    rootRightChild->left = NULL;
    rootRightChild->right = NULL;

    // Linking left and right children to the root node
    root->left = rootLeftChild;
    root->right = rootRightChild;


    // Alternatively using function

    init(root, 0);
    init(rootLeftChild, 1);
    init(rootRightChild, 2);
    root->left = rootLeftChild;
    root->right = rootRightChild;


    return 0;
}
