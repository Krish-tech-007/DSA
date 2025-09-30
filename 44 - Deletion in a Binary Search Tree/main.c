#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

void create(struct Node **node, int data){
    *node = (struct Node *) malloc(sizeof(struct Node));
    (*node)->data = data;
    (*node)->left = NULL;
    (*node)->right = NULL;
}

void link(struct Node *root, struct Node *left, struct Node *right){
    root->left = left;
    root->right = right;
}

void inOrder(struct Node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void freeTree(struct Node *root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void deleteAll(struct Node **rootNode, int data){
    struct Node *root = *rootNode;
    struct Node *prev = NULL;
    while(root!=NULL){
        if(root->data == data){
            freeTree(root);
            if(prev==NULL){
                printf("Deleting entire tree\n");
                *rootNode = NULL;
                return;
            }
            if(data < prev->data)
                prev->left = NULL;
            else
                prev->right = NULL;
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
    printf("Element not found\n");
}

int isLeafNode(struct Node *node){
    if(node->left == NULL && node->right == NULL)
        return 1;
    else
        return 0;
}

int countChildNodes(struct Node *node){
    int count = 0;
    if(node->left != NULL)
        count++;
    if(node->right != NULL)
        count++;
    return count;
}

struct Node* inOrderPredecessor(struct Node *root, struct Node *node){
    static struct Node *prev = NULL;
    if(node!=NULL){
        prev = node;
        inOrderPredecessor(root,node->left);
        if(node->data==root->data)
            return prev;
        inOrderPredecessor(root,node->right);

    }
};

void deleteNode(struct Node *root, int data){
    struct Node *prev = NULL;
    struct Node *toFree = NULL;
    while(root!=NULL){
        if(root->data == data){
            printf("Element found\n");
            int children = countChildNodes(root);
            switch(children){
            case 0:
                printf("Leaf node\n");
                toFree = root;
                if(data > prev->data)
                    prev->right = NULL;
                else
                    prev->left = NULL;
                free(toFree);
                break;
            case 1:
                printf("One Child node\n");
                toFree = root;
                if(data > prev->data)
                    prev->right = (root->left != NULL) ? root->left : root->right;
                else
                    prev->left = (root->left!=NULL) ? root->left : root->right;
                free(toFree);

                break;
            case 2:
                printf("Two child nodes\n");
                toFree = root;
                // Replace by either in order successor or in order predecessor
                struct Node *inOrderPre = inOrderPredecessor(root, root);
                printf("In Order predecessor: %d\n", inOrderPre->data);
                int inOrderPreData = inOrderPre->data;
                deleteNode(root, inOrderPre->data);
                toFree->data = inOrderPreData;
                break;
            }

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
    printf("Element does not exist\nCannot delete\n");
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
    create(&root, 9);
    create(&c1, 4);
    create(&c2, 11);
    create(&gc1, 2);
    create(&gc2, 7);
    create(&gc3, 13);
    create(&ggc1, 5);
    create(&ggc2, 8);
    create(&ggc3, 14);

    link(root,c1,c2);
    link(c1, gc1, gc2);
    link(c2, NULL, gc3);
    link(gc2, ggc1, ggc2);
    link(gc3, NULL, ggc3);

    printf("In Order: ");
    inOrder(root);
    printf("\n");

    int n;

    printf("Enter element to delete: ");
    scanf("%d", &n);

    deleteAll(&root, n);
    printf("In Order: ");
    inOrder(root);
    printf("\n");


    printf("Enter another element to delete: ");
    scanf("%d", &n);
    deleteNode(root, n);

    printf("In Order: ");
    inOrder(root);
    printf("\n");

    return 0;
}

/*
Code dump:
struct Node* inOrderPredecessor(struct Node *root, struct Node *node){
    static struct Node *prev = NULL;
    if(prev!=NULL)
        printf("Previous node: %d\n", prev->data);
    else
        printf("Previous node: NULL\n");
    if(node!=NULL){
        prev = node;
        printf("Root value when not null: %d\n", node->data);
        inOrderPredecessor(root,node->left);
        if(node->data==root->data && prev!=NULL){
            printf("In order predecessor: %d\n", prev->data);
            return prev;
        }
        inOrderPredecessor(root,node->right);

    }
};
*/
