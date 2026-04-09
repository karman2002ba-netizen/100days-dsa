#include <stdio.h>
#include <string.h>

#define MAX 100

int adj[MAX][MAX], indegree[MAX];
int queue[MAX];

void topoSort(int V) {
    int front = 0, rear = 0;

    
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    printf("Topological Order: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
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

    memset(adj, 0, sizeof(adj));
    memset(indegree, 0, sizeof(indegree));

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    topoSort(V);
    return 0;
}