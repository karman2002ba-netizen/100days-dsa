#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;


void dfs(int node, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }

    
    stack[++top] = node;
}


void topoSort(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }

    
    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n, m;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  
    }

    topoSort(n);

    return 0;
}