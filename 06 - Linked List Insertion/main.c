#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
void display(struct Node *ptr){
    printf("Displaying elements\n");
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertEnd(struct Node *ptr, int element){
    // O(n)
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = (struct Node *) malloc (1 * sizeof(struct Node));
    ptr->next->data = element;
    ptr->next->next = NULL;
}

void insertBeginning(struct Node **ptr, int element){
    // O(1)
    struct Node *head = (struct Node *) malloc(1 * sizeof(struct Node));
    head->data = element;
    head->next = *ptr;
    *ptr = head;

};

void freeMemory(struct Node *ptr){
    struct Node *temp;
    while(ptr!=NULL){
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }

}

void insertPosition(struct Node *ptr, int element, int pos){
    //O(n)
    struct Node *first, *second, *temp = ptr;
    for(int i=0; i<pos; i++){
        temp = temp->next;
        if(i==pos-2)
            first = temp;
        if(i==pos-1)
            second = temp;
    }
    struct Node *newElement = (struct Node *) malloc( 1 * sizeof(struct Node));
    newElement->next = second;
    newElement->data = element;
    first->next = newElement;
}

void insertAfter(int element, struct Node *node){
    //Insert after given Node
    // O(1)
    struct Node *newNode = (struct Node *) malloc(1 * sizeof(struct Node));
    newNode->data = element;
    newNode->next = node->next;
    node->next = newNode;
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
    display(head);
    insertEnd(head,5);
    display(head);
    insertPosition(head, 4, 5);
    display(head);
    struct Node *temp = head;
    printf("Inserting 100 after 4th element\n");
    for(int i = 0; i<3; i++){
        temp = temp->next;
    }
    insertAfter(100, temp);
    display(head);
    freeMemory(head);

    return 0;
}
