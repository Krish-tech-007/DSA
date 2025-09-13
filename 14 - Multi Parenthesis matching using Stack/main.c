#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    char *arr;
};

int push(struct Stack *s, char c){
    if(s->top == s->size-1){
        return 0;
    }
    s->top++;
    s->arr[s->top] = c;
}

int pop(struct Stack *s, char expected){
    if(s->top==-1){
        return 0;
    }
    else{
        char popped= s->arr[s->top];
        s->top--;
        if(popped==expected){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int isValid(char *expression){
    struct Stack s;
    s.size = sizeof(expression) / sizeof(char);
    s.top = -1;
    s.arr = (char *) malloc(sizeof(char) * s.size);

    for(int i = 0; *(expression+i)!='\0';i++){

        if(*(expression+i) == '(' || *(expression+i) == '{' || *(expression+i) == '['){
                int successful = push(&s, *(expression+i));
                if(!successful){
                    printf("Stack overflow\n");
                    return 0;
                }
        }

        else if(*(expression+i) == ')' || *(expression+i) == '}' || *(expression+i) == ']'){
            char expected;
            switch(*(expression+i)){
            case ')':
                expected = '(';
                break;
            case '}':
                expected = '{';
                break;
            case ']':
                expected = '[';
                 break;
            }
            int successful = pop(&s, expected);
            if(!successful){
                printf("Unmatched parenthesis\n");
                return 0;
            }
        }
    }

    if(s.top!=-1){
        printf("Stack not empty\nUnmatched opening brace\n");
        return 0;
    }

    return 1;

}

int main()
{

    char expression[100];
    printf("Enter an expression: ");
    scanf("%[^\n]", expression);

    int valid = isValid(expression);
    if(valid){
        printf("Valid expression\n");
    }
    else{
        printf("Invalid expression\n");
    }
    return 0;
}
