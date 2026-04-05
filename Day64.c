#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix (simpler than list)
int visited[MAX];
int queue[MAX];

void BFS(int n, int s) {
    int front = 0, rear = 0;

    
    queue[rear++] = s;
    visited[s] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, m, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // remove this line for directed graph
    }

    printf("Enter source: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    BFS(n, s);

    return 0;
}