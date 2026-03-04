#include <stdio.h>
#define MAX 5  

int stack[MAX];
int top = -1;


void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}