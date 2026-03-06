#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    int n, i, a, b, result;
    char token;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter postfix expression:\n");

    for (i = 0; i < n; i++) {
        scanf(" %c", &token);

        if (isdigit(token)) {
            push(token - '0');
        }
        else {
            b = pop();
            a = pop();

            switch(token) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator\n");
                    return 1;
            }

            push(result);
        }
    }

    printf("Result: %d\n", pop());

    return 0;
}