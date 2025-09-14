#include <stdio.h>
#include <stdlib.h>


/*
Drawbacks of using Queue implemented through arrays:
1. Space is not used efficiently: As front moves towards rear, empty spaces start to develop that are unused
One solution: When front == rear, make both front and rear -1 since the queue will be empty
This allows for reuse only when front==rear

Circular queue allows for utilization of spaces unused even before the queue is empty
*/

/*
i = i + 1 is linear increment

Circular increment is done using % operator
i = (i+1) % size is circular increment

For example,
If we have an array of size 6
Last index position is 5
If we increment 5, it should be 0
This formula achieves that
*/

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct Queue *q){
    if(q->rear == -1 && q->front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Queue *q){
    if( ((q->rear + 1) % q->size) == q->front){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct Queue *q, int val){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }
    else if(q->front == -1 && q->rear == -1){
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = val;
    }
    else{
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
    }
}

void dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    else if(q->front == q->rear){
        printf("Dequeued: %d\n", q->arr[q->front]);
        q->front = -1;
        q->rear = -1;
    }
    else{
        printf("Dequeued: %d\n", q->arr[q->front]);
        q->front = (q->front + 1) % q->size;
    }
}

void display(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for(int i = q->front; i!=q->rear; i = (i+1) % q->size){
        printf("%d ", q->arr[i]);
    }
    printf("%d\n", q->arr[q->rear]);
}
int main()
{
    struct Queue q;
    q.size = 5;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *) malloc(sizeof(int) * q.size);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    display(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 6);
    display(&q);


    free(q.arr);
    return 0;
}
