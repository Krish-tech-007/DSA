#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueueRear(struct Queue *q, int val){
    if((q->rear+1)%q->size == q->front){
        printf("Queue is full\nCannot Add element\n");
        return;
    }
    else if(q->front == -1 && q->rear == -1){
        q->front = q->rear = 0;
        q->arr[q->rear] = val;
    }
    else{
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
    }
}

void enqueueFront(struct Queue *q, int val){
    if((q->front-1)%q->size == q->rear){
        printf("Queue is full\nCannot Add elements\n");
        return;
    }
    else if(q->front == -1 && q->rear == -1){
        q->front = q->rear = 0;
        q->arr[q->front] = val;
    }
    else{
        q->front--;
        q->arr[q->front] = val;
    }
}
void dequeueFront(struct Queue *q){
    if(q->front == -1 && q->rear == -1){
        printf("Queue is empty\nCannot dequeue element\n");
        return;
    }
    else if(q->front == q->rear){
        q->front = q->rear = -1;
    }
    else{
        q->front++;
    }
}

void dequeueRear(struct Queue *q){
    if(q->front == -1 && q->rear == -1){
        printf("Queue is empty\nCannot dequeue element\n");
        return;
    }
    else if(q->front == q->rear){
        q->front = q->rear = -1;
    }
    else{
        q->rear--;
    }
}

void display(struct Queue *q){
    if(q->front == -1 && q->rear == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for(int i = q->front; i<=q->rear;i = (i+1) % q->size){
        printf("%d ", q->arr[i]);
    }
    printf("\n");

}

int main()
{
    struct Queue RIq; //enqueueFront is not allowed
    RIq.size = 5;
    RIq.front = -1;
    RIq.rear = -1;
    RIq.arr = (int *) malloc(sizeof(int) * RIq.size);

    printf("Restricted Input Queue\n");

    enqueueRear(&RIq, 1);
    enqueueRear(&RIq, 2);
    enqueueRear(&RIq, 3);
    display(&RIq);

    dequeueFront(&RIq);
    display(&RIq);

    dequeueRear(&RIq);
    display(&RIq);

    printf("\nRestricted Output Queue\n");

    struct Queue ROq; //dequeueRear is not allowed
    ROq.size = 5;
    ROq.front = ROq.rear = -1;
    ROq.arr = (int *) malloc(sizeof(int) * ROq.size);

    enqueueRear(&ROq, 1);
    enqueueRear(&ROq, 2);
    enqueueRear(&ROq, 3);
    display(&ROq);

    dequeueFront(&ROq);
    display(&ROq);

    enqueueFront(&ROq, 1);
    display(&ROq);

    return 0;
}
