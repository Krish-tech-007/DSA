#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

/*
void enqueue(struct Node **head, int data){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head==NULL){
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}


void dequeue(struct Node **head){
    if(*head==NULL){
        printf("Queue is empty\nCannot dequeue\n");
        return;
    }
    else{
        int dequeued = (*head)->data;
        struct Node *toFree = *head;
        *head = (*head)->next;
        free(toFree);
        printf("Dequeued: %d\n", dequeued);
    }
}
void display(struct Node *head){
    if(head==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
*/

struct Queue{
    struct Node *head;
    struct Node *tail;
};

void enqueue(struct Queue *q, int data){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(q->head==NULL && q->tail==NULL){
        q->head = newNode;
        q->tail = newNode;
    }
    else{
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

void dequeue(struct Queue *q){
    if(q->head==NULL && q->tail==NULL){
        printf("Queue is empty\nCannot dequeue\n");
        return;
    }
    else if(q->head == q->tail){
        struct Node *toFree = q->head;
        printf("Dequeued: %d\n", toFree->data);
        q->head = NULL;
        q->tail = NULL;
        free(toFree);
    }
    else{
        struct Node *toFree = q->head;
        q->head = q->head->next;
        printf("Dequeued: %d\n", toFree->data);
        free(toFree);
    }
}

void display(struct Queue *q){
    if(q->head==NULL && q->tail==NULL){
        printf("Queue is empty\nCannot dequeue\n");
        return;
    }
    printf("Queue: ");
    struct Node *ptr = q->head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


int main()
{

    struct Queue q;
    q.head = NULL;
    q.tail = NULL;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);
    dequeue(&q);
    display(&q);

    return 0;
}
