#include <stdio.h>
#include <stdlib.h>


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


void DFS(struct Graph* graph, int vertex) {
    
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    
    struct GraphNode* adjNode = graph->adjLists[vertex];
    while (adjNode != NULL) {
        if (graph->visited[adjNode->data] == 0) {
            DFS(graph, adjNode->data);
        }
        adjNode = adjNode->next;
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

    printf("Depth First Traversal starting from vertex 0: ");
    DFS(graph, 0);

    return 0;
}
