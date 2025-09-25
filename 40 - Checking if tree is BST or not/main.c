#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void inOrderTraversal(struct Node *root,int *arr, int *index){
    if(root!=NULL){
        inOrderTraversal(root->left, arr, index);
        arr[(*index)++] = root->data;
        inOrderTraversal(root->right, arr, index);
    }
}

int isSorted(int *arr, int size){
    for(int i = 0; i<size-1; i++){
        if(*(arr+i) > *(arr+i+1))
            return 0;
    }
    return 1;
}

int isBST(struct Node *root, int min, int max){
    if(root==NULL)
        return 1; // Empty tree is BST
    if(root->data < min || root->data > max)
        return 0;
    return isBST(root->left,min,root->data-1) && isBST(root->right, root->data+1,max);
    // Recurses left and right subtree
}


/*
int isBST(struct Node *root){
    static struct Node *prev = NULL; //prev means the node whose children we are checking
    // Static variables aren't thread-safe. If you're running this in a multithreaded environment, this approach could lead to race conditions.
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        return isBST(root->right); // Recursively checks the right subtree.
        // The result of this call becomes the result of the current function call.

    }
    else{
        return 1;
    }

}
*/

/*
Example of Binary Search Tree:
            9
          /   \
         4     11
        / \      \
       2   7      13
          / \       \
         5   8       14
*/
int main()
{
    struct Node *root, *c1, *c2, *gc1, *gc2, *gc3, *ggc1, *ggc2, *ggc3;
    init(&root, 9);
    init(&c1, 4);
    init(&c2, 11);
    init(&gc1, 2);
    init(&gc2, 7);
    init(&gc3, 13);
    init(&ggc1, 5);
    init(&ggc2, 8);
    init(&ggc3, 14);

    root->left = c1;
    root->right = c2;

    c1->left = gc1;
    c1->right = gc2;

    c2->right = gc3;

    gc2->left = ggc1;
    gc2->right = ggc2;

    gc3->right = ggc3;


    int *inOrder = (int *) malloc(sizeof(int) * 9);
    int index = 0;
    printf("Going into function\n");
    inOrderTraversal(root,inOrder, &index);

    if(isSorted(inOrder, 9))
        printf("Given Tree is a Binary Search Tree\n");
    else
        printf("Given Tree is not a Binary Search Tree\n");

    // Alternatively
    if(isBST(root, INT_MIN, INT_MAX))
        printf("Confirmed BST\n");
    else
        printf("Confirmed not a BST\n");

    return 0;
}
