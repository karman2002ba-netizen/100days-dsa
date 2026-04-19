#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int* visited, int** graph, int* graphColSize) {
    visited[node] = 1;

    for (int i = 0; i < graphColSize[node]; i++) {
        int next = graph[node][i];
        if (!visited[next]) {
            dfs(next, visited, graph, graphColSize);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // allocate graph
    int** graph = (int**)malloc((n + 1) * sizeof(int*));
    int* graphColSize = (int*)calloc((n + 1), sizeof(int));

    for (int i = 1; i <= n; i++) {
        graph[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][graphColSize[u]++] = v;
        graph[v][graphColSize[v]++] = u;
    }

    int* visited = (int*)calloc((n + 1), sizeof(int));

    // start DFS from node 1
    dfs(1, visited, graph, graphColSize);

    // check if all nodes visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}