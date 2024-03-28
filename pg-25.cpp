#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000


struct Edge {
    int src, dest, weight;
};


struct Graph {
    int V, E;
    struct Edge* edge;
};


struct subset {
    int parent;
    int rank;
};


struct Graph* createGraph(int V, int E);
void addEdge(struct Graph* graph, int src, int dest, int weight);
int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
int compare(const void* a, const void* b);
void KruskalMST(struct Graph* graph);


struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
    return graph;
}


void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->edge[graph->E].src = src;
    graph->edge[graph->E].dest = dest;
    graph->edge[graph->E].weight = weight;
    graph->E++;
}


int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


int compare(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}


void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V]; 
    int e = 0; 

    
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

   
    struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));

    
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    
    while (e < V - 1 && e < graph->E) {
       
        struct Edge next_edge = graph->edge[e++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

       
        if (x != y) {
            result[e - 1] = next_edge;
            Union(subsets, x, y);
        }
    }

   
    printf("Edges of the Minimum Spanning Tree:\n");
    for (int i = 0; i < e - 1; i++)
        printf("(%d, %d) -- Weight: %d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
}


int main() {
    int V = 4; 
    int E = 5; 
    struct Graph* graph = createGraph(V, E);

    
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 6);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 1, 3, 15);
    addEdge(graph, 2, 3, 4);

   
    KruskalMST(graph);

    return 0;
}
