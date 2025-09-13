#include <stdio.h>
#include <stdlib.h>

/*
Procedure:
1. If operand, add it to the expression
2. If operator, push it onto the stack.
If stack top is of higher or equal precedence, keep popping until current operator is of greater precedence than stack top.
Add the popped operators to the expression.
3. After the expression is iterated completely, pop the operators and add them to the part of the expression.
*/

struct Operator{
    char c;
    int precedence;
};

struct Stack{
    int size;
    int top;
    struct Operator *arr;
};

void push(struct Stack *s, struct Operator o){
    if(s->top==s->size-1){
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = o;
}

struct Operator pop(struct Stack *s){
    struct Operator o = s->arr[s->top];
    s->top--;
    return o;
};

int isEmpty(struct Stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

struct Operator stackTop(struct Stack *s){
    if(isEmpty(s)){
        struct Operator res;
        res.precedence = 0;
        res.c = '\0';
        return res;
    }
    return s->arr[s->top];
};

char *infixToPostfix(char *expression){
    struct Stack s;
    s.size = strlen(expression);
    s.top = -1;
    s.arr = (struct Operator *) malloc(sizeof(struct Operator) * s.size);

    char *result = (char *) malloc(sizeof(char) * s.size + 1);
    int index = 0;

    for(int i = 0; *(expression+i)!='\0'; i++){
        char c = *(expression+i);
        if(!(c == '+' || c == '-' ||c == '*' ||c == '/' ||c == '%')){
            result[index] = c;
            index++;
        }
        else{
            int precedence;
            if(c == '+' || c == '-')
                precedence = 1;
            else if(c == '*' ||c == '/' ||c == '%')
                precedence = 2;
            struct Operator o;
            o.c = c;
            o.precedence = precedence;

            struct Operator top = stackTop(&s);
            if(o.precedence > top.precedence){
                push(&s, o);
            }
            else{
                while(o.precedence <= (stackTop(&s).precedence)){
                    struct Operator popped = pop(&s);
                    result[index] = popped.c;
                    index++;
                }
                push(&s, o);
            }
        }
    }
    while(!isEmpty(&s)){
        struct Operator popped = pop(&s);
        result[index] = popped.c;
        index++;
    }
    result[index] = '\0';
    return result;
}
int main()
{
    char expression[100];
    printf("Enter infix expression: ");
    scanf("%[^\n]", expression);
    char * postfix = infixToPostfix(expression);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
