/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int timer = 1;

void dfs(int node, int parent, int vis[], int tin[], int low[], int mark[], int adj[MAX][MAX], int V) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    
    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (i == parent) continue;
            if (!vis[i]) {
                dfs(i, node, vis, tin, low, mark, adj, V);
                low[node] = (low[node] < low[i]) ? low[node] : low[i];
                if (low[i] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } else {
                low[node] = (low[node] < tin[i]) ? low[node] : tin[i];
            }
        }
    }
    if (child > 1 && parent == -1) {
        mark[node] = 1;
    }
}

void articulationPoints(int V, int adj[MAX][MAX]) {
    int vis[MAX] = {0};
    int tin[MAX], low[MAX], mark[MAX] = {0};
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, tin, low, mark, adj, V);
        }
    }
    
    printf("Articulation Points: ");
    int found = 0;
    for (int i = 0; i < V; i++) {
        if (mark[i]) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) printf("-1");
    printf("\n");
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
        adj[v][u] = 1;
        printf("Edge from %d to %d\n", u, v);
    }
    
    articulationPoints(V, adj);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

void dfs(int node, int parent, int disc[], int low[], bool vis[], int adj[MAX][MAX], int ap[], int *timer, int V) {
    vis[node] = true;
    disc[node] = low[node] = (*timer)++;
    int child = 0;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            int nbr = i;
            if (nbr == parent) continue;
            
            if (!vis[nbr]) {
                dfs(nbr, node, disc, low, vis, adj, ap, timer, V);
                low[node] = min(low[node], low[nbr]);
                
                if (low[nbr] >= disc[node] && parent != -1) {
                    ap[node] = 1;
                }
                child++;
            } else {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }
    
    if (parent == -1 && child > 1) {
        ap[node] = 1;
    }
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
        adj[v][u] = 1;
    }
    
    int timer = 0;
    int disc[MAX], low[MAX];
    bool vis[MAX] = {false};
    int ap[MAX] = {0};
    
    for (int i = 0; i < V; i++) {
        disc[i] = -1;
        low[i] = -1;
    }
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, -1, disc, low, vis, adj, ap, &timer, V);
        }
    }
    
    printf("Articulation points are as follows:\n");
    for (int i = 0; i < V; i++) {
        if (ap[i] != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void dfs(int node, int parent, int disc[], int low[], int vis[], int adj[MAX][MAX], int V, int ap[]) {
    static int time = 0;
    vis[node] = 1;
    disc[node] = low[node] = ++time;
    int children = 0;
    
    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (i == parent) continue;
            if (!vis[i]) {
                children++;
                dfs(i, node, disc, low, vis, adj, V, ap);
                low[node] = (low[node] < low[i]) ? low[node] : low[i];
                if (low[i] >= disc[node] && parent != -1)
                    ap[node] = 1;
            } else {
                low[node] = (low[node] < disc[i]) ? low[node] : disc[i];
            }
        }
    }
    if (parent == -1 && children > 1)
        ap[node] = 1;
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
        adj[v][u] = 1;
        printf("Edge from %d to %d\n", u, v);
    }
    
    int disc[MAX], low[MAX], vis[MAX] = {0}, ap[MAX] = {0};
    for (int i = 0; i < V; i++) {
        disc[i] = -1;
        low[i] = -1;
    }
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, -1, disc, low, vis, adj, V, ap);
        }
    }
    
    printf("Articulation points are as follows:\n");
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void dfs(int node, int parent, int disc[], int low[], int vis[], int adj[MAX][MAX], int V, int ap[]) {
    vis[node] = 1;
    disc[node] = low[node] = ++low[0];
    int children = 0;
    
    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (i == parent) continue;
            if (!vis[i]) {
                children++;
                dfs(i, node, disc, low, vis, adj, V, ap);
                low[node] = (low[node] < low[i]) ? low[node] : low[i];
                if (low[i] >= disc[node] && parent != -1)
                    ap[node] = 1;
            } else {
                low[node] = (low[node] < disc[i]) ? low[node] : disc[i];
            }
        }
    }
    if (parent == -1 && children > 1)
        ap[node] = 1;
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
        adj[v][u] = 1;
        printf("Edge from %d to %d\n", u, v);
    }
    
    int disc[MAX], low[MAX], vis[MAX] = {0}, ap[MAX] = {0};
    for (int i = 0; i < V; i++) {
        disc[i] = -1;
        low[i] = -1;
    }
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, -1, disc, low, vis, adj, V, ap);
        }
    }
    
    printf("Articulation points are as follows:\n");
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void dfs(int node, int parent, int disc[], int low[], int vis[], int adj[][MAX], int V, int ap[]) {
    static int time = 0;
    vis[node] = 1;
    disc[node] = low[node] = ++time;
    int children = 0;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (i == parent) continue;
            if (!vis[i]) {
                children++;
                dfs(i, node, disc, low, vis, adj, V, ap);
                low[node] = (low[node] < low[i]) ? low[node] : low[i];
                if (low[i] >= disc[node] && parent != -1)
                    ap[node] = 1;
            } else {
                low[node] = (low[node] < disc[i]) ? low[node] : disc[i];
            }
        }
    }
    if (parent == -1 && children > 1)
        ap[node] = 1;
}

void printArticulationPoints(int V, int ap[]) {
    printf("Articulation points are as follows:\n");
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
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
        adj[v][u] = 1;
        printf("Edge from %d to %d\n", u, v);
    }

    int disc[MAX], low[MAX], vis[MAX] = {0}, ap[MAX] = {0};
    for (int i = 0; i < V; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, -1, disc, low, vis, adj, V, ap);
        }
    }

    printArticulationPoints(V, ap);
    return 0;
}
