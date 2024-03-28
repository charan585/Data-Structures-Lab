#include <stdio.h>
#include <stdlib.h>

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
int peek(struct Stack *s);

int main() {
    struct Stack s;
    initializeStack(&s);

 
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

   
    printf("Top element of the stack: %d\n", peek(&s));

    
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));

    
    printf("Top element of the stack after popping: %d\n", peek(&s));

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
        return;
    }
    s->items[++(s->top)] = item;
}


int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->items[(s->top)--];
}


int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top];
}
