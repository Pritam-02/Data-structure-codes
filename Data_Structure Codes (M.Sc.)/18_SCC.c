/*#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void dfs(int node, int vis[], int adj[MAX][MAX], int V, int stack[], int *top) {
    vis[node] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !vis[i]) {
            dfs(i, vis, adj, V, stack, top);
        }
    }
    stack[++(*top)] = node;
}

void dfs3(int node, int vis[], int adjT[MAX][MAX], int V) {
    vis[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < V; i++) {
        if (adjT[node][i] && !vis[i]) {
            dfs3(i, vis, adjT, V);
        }
    }
}

int kosaraju(int V, int adj[MAX][MAX]) {
    int vis[MAX] = {0};
    int stack[MAX], top = -1;
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, V, stack, &top);
        }
    }
    
    int adjT[MAX][MAX] = {0};
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j]) {
                adjT[j][i] = 1;
            }
        }
    }
    
    for (int i = 0; i < V; i++) vis[i] = 0;
    int scc = 0;
    
    printf("Strongly Connected Components:\n");
    while (top >= 0) {
        int node = stack[top--];
        if (!vis[node]) {
            scc++;
            printf("Component %d: ", scc);
            dfs3(node, vis, adjT, V);
            printf("\n");
        }
    }
    return scc;
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    
    int adj[MAX][MAX] = {0};
    printf("Enter edges (from to):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        printf("Edge from %d to %d\n", u, v);
    }
    
    int ans = kosaraju(V, adj);
    printf("The number of strongly connected components is: %d\n", ans);
    
    return 0;
}*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void dfs(int node, int vis[], int adj[MAX][MAX], int V, int stack[], int *top) {
    vis[node] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !vis[i]) {
            dfs(i, vis, adj, V, stack, top);
        }
    }
    stack[++(*top)] = node;
}

void dfs3(int node, int vis[], int adjT[MAX][MAX], int V) {
    vis[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < V; i++) {
        if (adjT[node][i] && !vis[i]) {
            dfs3(i, vis, adjT, V);
        }
    }
}

int kosaraju(int V, int adj[MAX][MAX]) {
    int vis[MAX] = {0};
    int stack[MAX], top = -1;
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, V, stack, &top);
        }
    }
    
    int adjT[MAX][MAX] = {0};
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j]) {
                adjT[j][i] = 1;
            }
        }
    }
    
    for (int i = 0; i < V; i++) vis[i] = 0;
    int scc = 0;
    
    printf("Strongly Connected Components:\n");
    while (top >= 0) {
        int node = stack[top--];
        if (!vis[node]) {
            scc++;
            printf("Component %d: ", scc);
            dfs3(node, vis, adjT, V);
            printf("\n");
        }
    }
    return scc;
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    
    int adj[MAX][MAX] = {0};
    printf("Enter edges (from to):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        printf("Edge from %d to %d\n", u, v);
    }
    
    int ans = kosaraju(V, adj);
    printf("The number of strongly connected components is: %d\n", ans);
    
    return 0;
}

