#include <stdio.h>
#include <stdlib.h>


// Parenthesis matching problem - Checking if the brackets are balanced in a given expression
// Application: Syntax analysis by compiler

/*
Procedure:
1. Taking the expression as character array
2. Check if a given character is an opening or closing parenthesis, if not either of them, we ignore it
3. Whenever we encounter an opening parenthesis, we push it onto the stack
4. Whenever we encounter a closing parenthesis, we pop a corresponding opening parenthesis out of the stack
5. Do it till the expression ends

Condition for a balanced expression:
1. While popping, stack should not underflow. If it happens, then unbalanced expression
2. After expression ends, stack should be empty. If not empty, then unbalanced expression
*/

// Drawback
// This program does not tell if the overall expression is valid or nto
// For example: ((9*)(-1*)). Here the parenthesis are balanced but the expression is not valid

struct Stack{
    int size;
    int top;
    char *arr;
};

int push(struct Stack *s, char p){
    if(s->top == s->size-1){
        return 0;
    }
    else{
        s->top++;
        s->arr[s->top] = p;
        return 1;
    }
}

int pop(struct Stack *s){
    if(s->top==-1){
        return 0;
    }
    else{
        s->top--;
        return 1;
    }
}

int isValid(struct Stack *s, char *expression, int size){
    for(int i = 0; i<size; i++){

        if(*(expression+i) == '('){
            int successful = push(s, '(');
            if(!successful){
                printf("Stack overflow\n");
                return 0;
            }
        }

        else if(*(expression+i) == ')'){
            int successful = pop(s);
            if(!successful){
                printf("Unmatched closing brace\n");
                return 0;
            }
        }

    }

    if(s->top!=-1){
        printf("Stack not empty\n");
        return 0;
    }

    return 1;
}

int main()
{
    char expression[100];
    printf("Enter an expression: ");
    scanf("%[^\n]", expression);

    struct Stack s;
    s.size = 100;
    s.top = -1;
    s.arr = (char *) malloc(sizeof(char)*s.size);

    if(isValid(&s, expression, 100)){
        printf("Valid expression\n");
    }
    else{
        printf("Invalid expression\n");
    }

    return 0;
}
