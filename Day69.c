#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100


struct HeapNode {
    int vertex;
    int dist;
};


struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};


void swap(struct HeapNode *a, struct HeapNode *b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap *h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}


void push(struct MinHeap *h, int v, int d) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = d;

   
    while (i && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

struct HeapNode pop(struct MinHeap *h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapify(h, 0);
    return root;
}


void dijkstra(int graph[MAX][MAX], int n, int src) {

    int dist[MAX];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    push(&heap, src, 0);

    while (heap.size > 0) {
        struct HeapNode node = pop(&heap);
        int u = node.vertex;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    push(&heap, v, dist[v]);
                }
            }
        }
    }

    
    printf("Vertex\tDistance\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}


int main() {
    int n = 5;
    int graph[MAX][MAX] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    dijkstra(graph, n, 0);

    return 0;
}