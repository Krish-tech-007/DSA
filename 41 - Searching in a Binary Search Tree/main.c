#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

/*
Application of Binary Search Tree:
Fast search
Divides the elements to be searched in half each time
No. of comparisons done in the worst case = Height of the tree
Height of a tree can be greater than or equal to log n AND less than or equal to n
Time complexity:
Worst case: O(n), Example: When we search in a skewed tree
Best case : O(log n)
*/

void init(struct Node **node, int data){
    *node = (struct Node *) malloc(sizeof(struct Node));
    (*node)->data = data;
    (*node)->left = NULL;
    (*node)->right = NULL;
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

void inOrder(struct Node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int search(struct Node *root, int data){
    if(root==NULL){
        return 0;
    }
    if(root->data==data){
        return 1;
    }
    else if(data > root->data){
        search(root->right, data);
    }
    else{
        search(root->left, data);
    }
}
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
    printf("Enter element to search for: ");
    scanf("%d", &n);

    int isPresent = search(root,n);
    if(isPresent){
        printf("Element %d is present in the Binary Search Tree\n");
    }
    else{
        printf("Element %d is not present in the Binary Search Tree\n");
    }
    return 0;
}
