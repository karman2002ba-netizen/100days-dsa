#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int V;

// DFS function to detect cycle
bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            
            if (!visited[i] && dfs(i))
                return true;

            
            else if (recStack[i])
                return true;
        }
    }

    
    recStack[node] = false;
    return false;
}


bool isCycle() {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (isCycle())
        printf("Cycle detected in directed graph\n");
    else
        printf("No cycle in directed graph\n");

    return 0;
}