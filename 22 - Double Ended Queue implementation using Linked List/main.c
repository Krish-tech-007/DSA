#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
};

void enqueueRear(struct Queue *q, int val){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(q->front == NULL && q->rear==NULL){
        q->front = q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void enqueueFront(struct Queue *q, int val){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(q->front == NULL && q->rear == NULL){
        q->front = q->rear = newNode;
    }
    else{
        newNode->next = q->front;
        q->front = newNode;
    }
}

void dequeueFront(struct Queue *q){
    if(q->front == NULL && q->rear == NULL){
        printf("Queue is empty\nCannot dequeue\n");
        return;
    }
    struct Node *toFree = q->front;
    if(q->front == q->rear){
        q->front = q->rear = NULL;
    }
    else{
        q->front = q->front->next;
    }
    free(toFree);
}

void dequeueRear(struct Queue *q){
    if(q->front == NULL && q->rear == NULL){
        printf("Queue is empty\nCannot dequeue\n");
        return;
    }
    struct Node *toFree = q->rear;
    if(q->front == q->rear){
        q->front = q->rear = NULL;
    }
    else{
        struct Node *temp = q->front;
        while(temp->next != q->rear){
            temp = temp->next;
        }
        q->rear = temp;
        q->rear->next = NULL;
    }
    free(toFree);
}

void display(struct Queue *q){
    struct Node *temp = q->front;
    if(q->front == NULL && q->rear == NULL){
       printf("Queue is empty\n");
       return;
    }
    printf("Queue: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

int main()
{
    printf("Restricted Input Queue\n");
    struct Queue RIq; //enqueue front not allowed
    RIq.front = NULL;
    RIq.rear = NULL;
    display(&RIq);
    enqueueRear(&RIq, 1);
    enqueueRear(&RIq, 2);
    enqueueRear(&RIq, 3);
    display(&RIq);

    dequeueRear(&RIq);
    display(&RIq);

    dequeueFront(&RIq);
    display(&RIq);

    printf("Restricted Output Queue\n"); //dequeue rear not allowed
    struct Queue ROq;
    ROq.front = NULL;
    ROq.rear = NULL;

    display(&ROq);

    enqueueFront(&ROq, 0);
    display(&ROq);

    enqueueRear(&ROq, 1);
    enqueueRear(&ROq, 2);
    display(&ROq);

    dequeueFront(&ROq);
    display(&ROq);

    return 0;
}
