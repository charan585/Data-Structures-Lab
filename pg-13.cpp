#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


struct Queue {
    int front, rear, size;
    int items[MAX_SIZE];
};


void initializeQueue(struct Queue *q);
int isEmpty(struct Queue *q);
int isFull(struct Queue *q);
void enqueue(struct Queue *q, int item);
int dequeue(struct Queue *q);
void displayQueue(struct Queue *q);

int main() {
    struct Queue q;
    initializeQueue(&q);

    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

   
    printf("Queue: ");
    displayQueue(&q);

    
    printf("Dequeued element: %d\n", dequeue(&q));

   
    printf("Queue after dequeue: ");
    displayQueue(&q);

    return 0;
}


void initializeQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}


int isEmpty(struct Queue *q) {
    return (q->size == 0);
}


int isFull(struct Queue *q) {
    return (q->size == MAX_SIZE);
}


void enqueue(struct Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = item;
    q->size++;
}


int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return item;
}


void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i;
    for (i = 0; i < q->size; i++) {
        printf("%d ", q->items[(q->front + i) % MAX_SIZE]);
    }
    printf("\n");
}
