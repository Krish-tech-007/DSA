#include <stdio.h>
#include <stdlib.h>

// We can always set a custom size if we want to

// We can also make top a global variable if we want to, outside the scope of all other functions

struct Node {
    int data;
    struct Node * next;
};

void push(struct Node **top, int value){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

void pop(struct Node **top){
    if(*top==NULL){
        printf("Stack Underflow\n");
        return;
    }
    struct Node *toFree = *top;
    *top = (*top)->next;
    free(toFree);
}

void peek(struct Node *top){
    if(top==NULL){
        printf("Stack Underflow\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

void peekAt(struct Node *top, int pos){
    for(int i = 0; i<pos && top!=NULL;i++){
        top = top->next;
    }
    if(top!=NULL){
        printf("Value: %d\n", top->data);
    }
    else{
        printf("Position does not exist\n");
    }
}

void display(struct Node *top){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Displaying the elements\n");
    while(top!=NULL){
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

void stackTop(struct Node *top){
    if(top==NULL){
        printf("Underflow\n");
        return;
    }
    printf("Stack top: %d\n", top->data);
}

void stackBottom(struct Node *top){
    if(top==NULL){
        printf("Underflow\n");
        return;
    }
    while(top->next!=NULL){
        top = top->next;
    }
    printf("Stack bottom: %d\n", top->data);
}
int main()
{
    //struct Node *top = (struct Node *) malloc(sizeof(struct Node));
    //top->data = 0;
    //top->next = NULL;

    struct Node *top = NULL;
    push(&top, 0);
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);
    display(top);
    pop(&top);
    display(top);
    peekAt(top, 3);
    stackTop(top);
    stackBottom(top);

    return 0;
}
