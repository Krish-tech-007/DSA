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

void push(struct Stack *sptr, int value){
    if(sptr->top==sptr->size-1){
        printf("Stack is full\n");
        return;
    }
    sptr->top++;
    sptr->arr[top] = value;
}


int main()
{
    struct Stack s;
    s.size = 80;
    s.top = -1;
    s.arr = (int *) malloc(s.size * sizeof(int));

    return 0;
}
