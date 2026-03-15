#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int x)
{
    if((front == 0 && rear == MAX-1) || front == rear+1)
        printf("Overflow\n");

    else if(front == -1)
        front = rear = 0;

    else if(front == 0)
        front = MAX-1;

    else
        front--;

    deque[front] = x;
}

void insertRear(int x)
{
    if((front == 0 && rear == MAX-1) || front == rear+1)
        printf("Overflow\n");

    else if(front == -1)
        front = rear = 0;

    else if(rear == MAX-1)
        rear = 0;

    else
        rear++;

    deque[rear] = x;
}

void deleteFront()
{
    if(front == -1)
        printf("Underflow\n");

    else
    {
        printf("Deleted: %d\n", deque[front]);

        if(front == rear)
            front = rear = -1;

        else if(front == MAX-1)
            front = 0;

        else
            front++;
    }
}

void deleteRear()
{
    if(front == -1)
        printf("Underflow\n");

    else
    {
        printf("Deleted: %d\n", deque[rear]);

        if(front == rear)
            front = rear = -1;

        else if(rear == 0)
            rear = MAX-1;

        else
            rear--;
    }
}

void display()
{
    if(front == -1)
        printf("Deque is empty\n");

    else
    {
        int i = front;
        printf("Deque elements: ");

        while(i != rear)
        {
            printf("%d ", deque[i]);
            i = (i+1) % MAX;
        }

        printf("%d\n", deque[rear]);
    }
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();

    deleteFront();
    display();

    deleteRear();
    display();

    return 0;
}