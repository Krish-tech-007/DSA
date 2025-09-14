#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(struct Queue *q, int value){
    if(q->rear == q->size-1){
        printf("Queue is full\n");
    }
    else if(q->front == -1 && q->rear == -1){
        q->front++;
        q->rear++;
        q->arr[q->rear] = value;
    }
    else{
        q->rear++;
        q->arr[q->rear] = value;
    }
}

void dequeue(struct Queue *q){
    if(q->rear == -1 && q->front == -1){
        printf("Queue is empty\n");
        return;
    }
    else if(q->front==q->rear){
        printf("Dequeued %d\n", q->arr[q->front]);
        q->rear=-1;
        q->front=-1;
    }
    else{
        printf("Dequeued %d\n", q->arr[q->front]);
        q->front++;
    }
}

void dequeueMove(struct Queue *q){
    if(q->rear==-1 && q->front==-1){
        printf("Queue is empty\n");
        return;
    }
    else if(q->front==q->rear){
        printf("Dequeued %d\n", q->arr[q->front]);
        q->front = -1;
        q->rear = -1;
    }
    else{
        printf("Dequeued %d\n", q->arr[q->front]);
        for(int i = 1; i<=q->rear; i++){
            q->arr[i-1] = q->arr[i];
        }
        q->rear--;
    }
}

void display(struct Queue *q){
    if(q->front == -1 && q->rear == -1){
        printf("Empty queue\n");
        return;
    }
    printf("Queue: ");
    for(int i = q->front; i<=q->rear; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    q.size = 100;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *) malloc(sizeof(int) * q.size);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);

    printf("\nDifferent Implementation\n\n");

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);
    dequeueMove(&q);
    display(&q);
    dequeueMove(&q);
    display(&q);
    dequeueMove(&q);
    display(&q);

    free(q.arr);

    return 0;
}
