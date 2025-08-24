#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr){
    printf("Displaying the elements\n");
    while(ptr!=NULL){
       printf("%d ", ptr->data);
       ptr = ptr->next;
    }
    printf("\n");
}

void freeMemory(struct Node *ptr){
    struct Node *temp;
    while(ptr!=NULL){
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}

void insertBeginning(struct Node **ptr, int data){
    struct Node *newNode = (struct Node *) malloc(1 * sizeof(struct Node));
    newNode->data = data;
    newNode->next = *ptr;
    *ptr = newNode;
}

void insertEnd(struct Node *ptr, int data){
    struct Node *newNode = (struct Node *) malloc(1 * sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next = newNode;
}

void insertIndex(struct Node *ptr, int data, int index){
    struct Node *newNode = (struct Node *) malloc(1 * sizeof(struct Node));
    newNode->data = data;
    for(int i = 0; i<index-1; i++){
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void insertAfter(struct Node *after, int data){
    struct Node *newNode = (struct Node *) malloc(1*sizeof(struct Node));
    newNode->data = data;
    newNode->next = after->next;
    after->next = newNode;
}


//DELETION

void deleteFirst(struct Node **ptr){
    // O(n)
    struct Node *head = *ptr;
    *ptr = (*ptr)->next;
    free(head);
}

void deleteIndex(struct Node *ptr, int index){
    // O(n)
    for(int i = 0; i<index-1; i++){
        ptr = ptr->next;
    }
    struct Node *toDelete = ptr->next;
    ptr->next = ptr->next->next;
    free(toDelete);
}

void deleteEnd(struct Node *ptr){
    if(ptr==NULL || ptr->next==NULL){
        free(ptr);
        return;
    }
    while(ptr->next->next!=NULL){
        ptr = ptr->next;
    }
    struct Node *toDelete = ptr->next->next;
    ptr->next = NULL;
    free(toDelete);
}

void deleteValue(struct Node *ptr, int value){
    if(ptr==NULL){
        printf("No elements\n");
        return;
    }
    while(ptr->next->data!=value && ptr->next->next!=NULL){
        ptr = ptr->next;
    }
    if(ptr->next->data == value){
    struct Node *toDelete = ptr->next;
    ptr->next = ptr->next->next;
    free(toDelete);
    }

}
int main()
{
    struct Node *head = (struct Node *) malloc(1*sizeof(struct Node));
    head->data = 0;
    head->next = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertBeginning(&head, -1);
    traverse(head);
    deleteFirst(&head);
    traverse(head);
    deleteIndex(head, 1);
    traverse(head);
    deleteEnd(head);
    traverse(head);
    insertEnd(head,2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    traverse(head);
    deleteValue(head,2);
    traverse(head);
    freeMemory(head);
    return 0;
}
