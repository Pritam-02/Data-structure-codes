#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    int weight;  // To store the weight of the edge
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int v;
    struct Node** array; // Array of pointers to adjacency lists
};

// Function to create a new node
struct Node* cnode(int x, int w) {
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    q->data = x;
    q->weight = w;
    q->next = NULL;
    return q;
}

// Function to create a graph
struct Graph* cGraph(int v) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->v = v;

    // Allocate memory for adjacency list array
    graph->array = (struct Node**)malloc(v * sizeof(struct Node*));

    // Initialize each adjacency list as NULL
    for (int i = 0; i < v; i++) {
        graph->array[i] = NULL;
    }

    return graph;
}

// Function to add an edge
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Add edge from src to dest
    struct Node* temp = cnode(dest, weight);
    temp->next = graph->array[src];
    graph->array[src] = temp;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->v; v++) {
        struct Node* trav = graph->array[v];
        printf("Vertex %d: ", v);
        while (trav != NULL) {
            printf("-> %d (weight %d) ", trav->data, trav->weight);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = cGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    // Print the graph
    printf("\nAdjacency List Representation of the Graph:\n");
    printGraph(graph);

    return 0;
}
