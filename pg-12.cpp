#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define MAX_SIZE 100


struct Stack {
    int top;
    int items[MAX_SIZE];
};


void initializeStack(struct Stack *s);
int isEmpty(struct Stack *s);
int isFull(struct Stack *s);
void push(struct Stack *s, int item);
int pop(struct Stack *s);
int evaluatePostfix(char* expression);

int main() {
    char expression[MAX_SIZE];

   
    printf("Enter a postfix expression: ");
    fgets(expression, MAX_SIZE, stdin);

    
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}


void initializeStack(struct Stack *s) {
    s->top = -1;
}


int isEmpty(struct Stack *s) {
    return (s->top == -1);
}


int isFull(struct Stack *s) {
    return (s->top == MAX_SIZE - 1);
}


void push(struct Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = item;
}


int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}


int evaluatePostfix(char* expression) {
    struct Stack s;
    initializeStack(&s);

    int i, operand1, operand2, result;
    char ch;

    for (i = 0; expression[i] != '\0'; i++) {
        ch = expression[i];

        if (isdigit(ch)) {
            
            push(&s, ch - '0'); 
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
          
            operand2 = pop(&s);
            operand1 = pop(&s);

            switch (ch) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
            }
        }
    }

    
    result = pop(&s);
    return result;
}
