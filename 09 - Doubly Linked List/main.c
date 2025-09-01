#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
struct Node *prev;
}; //Benefit of doubly linked list, we can easily reverse the linked list by interchanging head and last pointer

void traverseForward(struct Node *head){
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void traverseBackward(struct Node *last){
    while(last!=NULL){
        printf("%d ", last->data);
        last = last->prev;
    }
}

void insertBeginning(struct Node **head, int data){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->prev = NULL;
    newNode->next = *head;

    (*head)->prev = newNode;

    *head = newNode;
}

void insertEnd(struct Node *head, int data){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

void insertAfter(struct Node *node, int data){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = node;
    newNode->next = node->next;
    if(node->next != NULL){
        node->next->prev = newNode;
    }
    node->next = newNode;
}

void insertIndex(struct Node **head, int data, int index){
    if(index == 0){
        insertBeginning(head, data);
        return;
    }
    struct Node *temp = *head;
    for(int i = 0; i<index-1 && temp->next != NULL; i++){
        temp=temp->next;
    }

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = temp;
    newNode->next = temp->next;
    if(newNode->next!=NULL){
        newNode->next->prev = newNode;
    }
    temp->next = newNode;

}

void freeMemory(struct Node *head){
    struct Node *temp;
    while(head!=NULL){
        temp = head->next;
        free(head);
        head = temp;
    }
}

void deleteFirst(struct Node **head){
    if(*head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *first = *head;
    (*head)->next->prev = NULL;
    *head = (*head)->next;
    free(first);
}

void deleteLast(struct Node **head){
    if(*head == NULL){
        printf("Linked list is empty\n");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deleteIndex(struct Node **head, int index){
    if(*head==NULL){
        printf("Empty Linked List\n");
        return;
    }
    if(index == 0){
        deleteFirst(head);
        return;
    }
    struct Node *temp = *head;
    for(int i =0; i<index-1 && temp!=NULL; i++){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("Index out of bound\n");
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    if(toDelete->next != NULL){
        toDelete->next->prev = temp;
    }
    free(toDelete);
}

void search(struct Node **head, int value){
    if(*head==NULL){
        printf("Empty linked list\n");
        return;
    }
    struct Node *temp = *head;
    while(temp!=NULL){
        if(temp->data == value){
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

void deleteValue(struct Node **head, int value){
    if(*head == NULL){
        printf("Empty linked list\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *toDelete;
    while(temp!=NULL){
        if(temp->data == value){
            toDelete = temp;
            if(toDelete->prev == NULL){
                deleteFirst(head);
                return;
            }
            else if(toDelete->next == NULL){
                deleteLast(head);
                return;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = toDelete->prev;
                free(toDelete);
                return;
            }
        }
        temp = temp->next;
    }
    printf("Value not found\n");
}

int main()
{
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;
    return 0;
}
