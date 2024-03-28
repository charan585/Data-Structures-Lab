#include <stdio.h>
#include <stdlib.h>


struct Queue {
    int front, rear;
    int capacity;
    int* array;
};


struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}


int isFull(struct Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}


int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->array[++queue->rear] = item;
    if (queue->front == -1)
        queue->front = 0;
}


int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    return item;
}


struct GraphNode {
    int data;
    struct GraphNode* next;
};


struct Graph {
    int numVertices;
    struct GraphNode** adjLists;
    int* visited;
};


struct GraphNode* newGraphNode(int data) {
    struct GraphNode* newNode = (struct GraphNode*)malloc(sizeof(struct GraphNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjLists = (struct GraphNode**)malloc(numVertices * sizeof(struct GraphNode*));
    graph->visited = (int*)malloc(numVertices * sizeof(int));

    int i;
    for (i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;  
    }

    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
   
    struct GraphNode* newNode = newGraphNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

   
    newNode = newGraphNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}


void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue(graph->numVertices);

    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct GraphNode* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->data;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}


int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Breadth First Traversal starting from vertex 0: ");
    BFS(graph, 0);

    return 0;
}
