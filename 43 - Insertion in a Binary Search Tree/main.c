#include <stdio.h>
#include <stdlib.h>

/*
In a binary search tree: Duplicates are not allowed
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
void insert(struct Node *root, int data){
    struct Node *prev = NULL;
    while(root!=NULL){
        if(root->data == data){
            printf("Element already exists\nCannot insert\n");
            return;
        }
        else{
        prev = root;

        if(data > root->data)
            root = root->right;
        else
            root = root->left;
        }

    }
    if(prev!=NULL){
        struct Node *ptr;
        init(&ptr, data);
        if(data > prev->data){
            prev->right = ptr;
        }
        else
            prev->left = ptr;
    }
}

void inOrder(struct Node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void link(struct Node *root, struct Node *left, struct Node *right){
    root->left = left;
    root->right = right;
}
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

    link(root, c1, c2);
    link(c1, gc1, gc2);
    link(c2, NULL, gc3);
    link(gc2, ggc1, ggc2);
    link(gc3, NULL, ggc3);

    printf("In order: ");
    inOrder(root);
    printf("\n");

    int n;
    printf("Enter element to insert: ");
    scanf("%d", &n);

    insert(root, n);
    printf("In Order: ");
    inOrder(root);
    printf("\n");

    if(n==6)
        printf("%d\n", ggc1->right->data);


    return 0;
}
