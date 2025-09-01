#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

//Operations: Insertion, Deletion, Search, Traversal

void traverse(struct Node *head){
    if(head==NULL){
        printf("Linked list empty\n");
        return;
    }
    printf("Displaying the circular linked list\n");
    struct Node *ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
    printf("\n");
}

void search(struct Node *head, int value){
    if(head==NULL){
        printf("Empty linked list\n");
        return;
    }
    printf("Searching the circular linked list\n");
    struct Node *temp = head;
    do{
        if(temp->data==value){
            printf("Element %d found\n", value);
            return;
        }
        temp = temp->next;
    }while(temp!=head);
    printf("Element %d not found\n", value);
}

void input(struct Node *head){
    if(head==NULL){
        printf("Linked List does not exist.\n");
        return;
    }
    struct Node *ptr = head;
    int n;
    printf("Enter number of elements to enter: ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        printf("Enter element no. %d: ", (i+1));
        scanf("%d", &(newNode->data));
        ptr->next = newNode;
        ptr = ptr->next;
    }
    ptr->next = head;
}

void insertEnd(struct Node **ptr, int data){
    struct Node *head = *ptr;
    struct Node *temp = *ptr;
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    if(*ptr==NULL){
        *ptr=newNode;
        newNode->next = newNode;
        return;
    }
    do{
        temp=temp->next;
    }while(temp->next!=head);
    temp->next = newNode;

}

void insertBeginning(struct Node **ptr, int data){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *ptr;
    if(*ptr==NULL){
        *ptr=newNode;
        newNode->next = newNode;
        return;
    }
    struct Node *temp = *ptr;
    do{
        temp = temp->next;
    }while(temp->next!=*ptr);
    temp->next = newNode;
    *ptr = newNode;
}

void insertIndex(struct Node **ptr, int data, int pos){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    if(*ptr==NULL){
        *ptr = newNode;
        newNode->next = newNode;
        return;
    }
    if(pos==0){
        insertBeginning(ptr, data);
        return;
    }
    struct Node *temp = *ptr;
    for(int i = 0; i<pos-1;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfter(struct Node **ptr, int data, struct Node *after){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    if(*ptr==NULL){
        if(after==NULL){
            *ptr = newNode;
            newNode->next = newNode;
        }
        else{
            *ptr = after;
            after->next = newNode;
            newNode->next = after;
        }
        return;
    }
    newNode->next = after->next;
    after->next = newNode;
}

void deleteFirst(struct Node **ptr){
    if(*ptr == NULL){
        printf("Empty Linked List\n");
        return;
    }
    if((*ptr)->next == *ptr){
        printf("Circular linked list is now empty\n");
        free(*ptr);
        *ptr=NULL;
        return;
    }
    struct Node *temp = *ptr;
    struct Node *head = *ptr;
    do{
        temp=temp->next;
    }while(temp->next!=head);

    temp->next = head->next;
    *ptr = head->next; //Updating the original pointer
    free(head);
}

void deleteLast(struct Node **ptr){
    struct Node *head = *ptr;
    if(*ptr==NULL){
        printf("Empty Linked List\n");
        return;
    }
    if((*ptr)->next == *ptr){
        printf("Circular linked list is now empty\n");
        free(*ptr);
        *ptr=NULL;
        return;
    }
    struct Node *temp = *ptr;
    do{
        temp = temp->next;
    }while(temp->next->next!=head);
    struct Node *toDelete = temp->next;
    temp->next = head;
    free(toDelete);
}

void deleteIndex(struct Node **ptr, int index){
    if(*ptr==NULL){
        printf("Linked list is empty\n");
        return;
    }
    if(index==0){
        deleteFirst(ptr);
        return;
    }
    struct Node *temp = *ptr;
    for(int i = 0; i<index-1;i++){
        temp = temp->next;
    }
    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);-
}

void freeMemory(struct Node *ptr){
    struct Node *head = ptr;
    struct Node *temp;
    do{
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }while(ptr!=head);
}

int main()
{
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;
    input(head);
    traverse(head);
    insertEnd(&head, 10);
    traverse(head);
    search(head,10);
    search(head,11);
    freeMemory(head);

    return 0;
}
