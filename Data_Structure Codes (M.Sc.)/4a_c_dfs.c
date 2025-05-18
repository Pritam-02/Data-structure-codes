#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix
int visited[MAX_NODES];
int dfs_tree[MAX_NODES];
int component_count = 0;
int n; // Number of nodes

void DFS(int node, int parent) {
    visited[node] = 1;
    dfs_tree[node] = parent; // Record the parent in the DFS tree

    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            DFS(i, node); // Recursive DFS
        }
    }
}

void findComponents() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            component_count++;
            printf("Starting new DFS for component %d from node %d\n", component_count, i);
            DFS(i, -1); // Start a new DFS tree
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph and visited arrays
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
        dfs_tree[i] = -1; // Initialize DFS tree with -1
    }

    // Read edges
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Since the graph is undirected
    }

    // Find components and build DFS tree
    findComponents();

    // Print DFS tree
    printf("\nDFS Tree:\n");
    for (int i = 0; i < n; i++) {
        if (dfs_tree[i] != -1) {
            printf("Node %d -> Parent %d\n", i, dfs_tree[i]);
        } else {
            printf("Node %d -> Root of DFS Tree\n", i);
        }
    }

    // Print the number of components
    printf("\nNumber of connected components: %d\n", component_count);

    return 0;
}
