//Min Heap Implementation
#include <stdio.h>
#define MAX 100
int heap[MAX];
int size = 0;
void insert(int x)
{
    if(size == MAX)
    {
        printf("Heap is full\n");
        return;
    }
    heap[size] = x;
    size++;
    int i = size - 1;
    while(i != 0 && heap[i] < heap[(i - 1) / 2])
    {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
void deleteMin()
{
    if(size == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    printf("Deleted: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    int i = 0;
    while((2 * i + 1 < size && heap[i] > heap[2 * i + 1]) || (2 * i + 2 < size && heap[i] > heap[2 * i + 2]))
    {
        int minIndex = i;
        if(2 * i + 1 < size && heap[minIndex] > heap[2 * i + 1])
            minIndex = 2 * i + 1;
        if(2 * i + 2 < size && heap[minIndex] > heap[2 * i + 2])
            minIndex = 2 * i + 2;
        int temp = heap[i];
        heap[i] = heap[minIndex];
        heap[minIndex] = temp;
        i = minIndex;
    }
}
void display()
{
    if(size == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    printf("Heap elements: ");
    for(int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}
int main()
{
    insert(5);
    insert(3);
    insert(8);
    insert(1);
    display();
    deleteMin();
    display();
    return 0;
}