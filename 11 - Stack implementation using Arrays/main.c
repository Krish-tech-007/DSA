#include <stdio.h>
#include <stdlib.h>

// When implementing using array, top is not a pointer, it stores index value
// If top is -1 means stack is empty

// However, a pointer can also be used

// Features:
// Fixed size
// Track top element

// Most of the operations can be done in O(1)

struct Stack{
    int size;
    int top;
    int *arr; // For heap allocation
};

int isFull(struct Stack *sptr){
     if(sptr->top==sptr->size-1)
        return 1;
     else
        return 0;
}

int isEmpty(struct Stack *sptr){
    if(sptr->top==-1)
        return 1;
    else
        return 0;
}
void push(struct Stack *sptr, int value){
    if(isFull(sptr)){
        printf("Stack is full\n");
        return;
    }
    sptr->top++;
    sptr->arr[sptr->top] = value;
}

void pop(struct Stack *sptr){
    if(isEmpty(sptr)){
        printf("Stack is empty\n");
        return;
    }
    sptr->top--;
}

void peek(struct Stack *sptr){
    if(isEmpty(sptr)){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", sptr->arr[sptr->top]);
}

void peekAt(struct Stack *sptr, int pos){
    if(pos<=0){
        printf("Invalid parameter\n");
        return;
    }
    int index = sptr->top - pos;
    if(index<0){
        printf("Index does not exist\n");
        return;
    }
    printf("Element: %d\n", sptr->arr[index]);
}

void display(struct Stack *sptr){
    if(isEmpty(sptr)){
        printf("Stack is empty\n");
        return;
    }
    printf("Displaying the elements\n");
    for(int i = sptr->top; i>=0; i--){
        printf("%d ", sptr->arr[i]);
    }
    printf("\n");
}

void stackBottom(struct Stack *sptr){
    if(isEmpty(sptr)){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack Bottom: %d\n", sptr->arr[0]);
}

void stackTop(struct Stack *sptr){
    if(isEmpty(sptr)){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack Top: %d\n", sptr->arr[sptr->top]);
}

int main()
{
    struct Stack s;
    s.size = 80;
    s.top = -1;
    s.arr = (int *) malloc(s.size * sizeof(int)); // Integer array

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    display(&s);
    peek(&s);
    pop(&s);
    display(&s);
    peekAt(&s,1);
    return 0;
}
