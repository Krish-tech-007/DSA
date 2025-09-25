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

/*
       10
      /  \
     5    15
    / \     \
   2   7     20

 Step-by-Step Execution of isBST(root)
We’ll simulate the in-order traversal: left → root → right
1. Start at root: 10
- Call isBST(10)
- prev = NULL
- Go left: call isBST(5)
2. At node 5
- Go left: call isBST(2)
3. At node 2
- Go left: isBST(NULL) → returns 1
- Compare prev (still NULL) → no violation
- Set prev = 2
- Go right: isBST(NULL) → returns 1
- Return 1 to caller (5)
4. Back at node 5
- Compare prev = 2 with 5 → OK (5 > 2)
- Set prev = 5
- Go right: call isBST(7)
5. At node 7
- Go left: isBST(NULL) → returns 1
- Compare prev = 5 with 7 → OK (7 > 5)
- Set prev = 7
- Go right: isBST(NULL) → returns 1
- Return 1 to caller (5), then to 10
6. Back at node 10
- Compare prev = 7 with 10 → OK (10 > 7)
- Set prev = 10
- Go right: call isBST(15)
7. At node 15
- Go left: isBST(NULL) → returns 1
- Compare prev = 10 with 15 → OK (15 > 10)
- Set prev = 15
- Go right: call isBST(20)
8. At node 20
- Go left: isBST(NULL) → returns 1
- Compare prev = 15 with 20 → OK (20 > 15)
- Set prev = 20
- Go right: isBST(NULL) → returns 1
- Return 1 all the way up

Every node passed the BST check. So isBST(root) returns 1.

Not BST
       10
      /  \
     5    15
    / \   /
   2   12 6

This tree violates BST rules:
- Node 12 is in the left subtree of 10 but is greater than 10 → ❌
- Node 6 is in the right subtree of 10 but is less than 10 → ❌

Step-by-Step Execution of isBST(root)
We’ll simulate the in-order traversal: left → root → right
1. Start at root: 10
- Call isBST(10)
- prev = NULL
- Go left: call isBST(5)
2. At node 5
- Go left: call isBST(2)
3. At node 2
- Go left: isBST(NULL) → returns 1
- Compare prev = NULL → OK
- Set prev = 2
- Go right: isBST(NULL) → returns 1
- Return 1 to caller (5)
4. Back at node 5
- Compare prev = 2 with 5 → OK (5 > 2)
- Set prev = 5
- Go right: call isBST(12)
5. At node 12
- Go left: isBST(NULL) → returns 1
- Compare prev = 5 with 12 → OK (12 > 5)
- Set prev = 12
- Go right: isBST(NULL) → returns 1
- Return 1 to caller (5), then to 10
6. Back at node 10
- Compare prev = 12 with 10 → ❌ Violation!
- 10 <= 12 → violates BST rule
- Return 0 immediately

❌ Final Result
The function returns 0 because it detects that 10 is not greater than the previously visited node 12. This breaks the in-order increasing sequence required for a BST.

*/
