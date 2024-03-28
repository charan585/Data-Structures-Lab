#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int element) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue %d\n", element);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = element;
    printf("%d enqueued to queue\n", element);
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int element = queue[front];
    front++;
    printf("%d dequeued from queue\n", element);
    return element;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    return 0;
}
