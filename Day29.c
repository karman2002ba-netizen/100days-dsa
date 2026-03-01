#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to rotate list
struct Node* rotateRight(struct Node* head, int k) {
    
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: Find length
    struct Node* temp = head;
    int length = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Step 2: Make it circular
    temp->next = head;

    // Step 3: Reduce k
    k = k % length;
    int steps = length - k;

    struct Node* newTail = head;

    // Step 4: Move to new tail
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 5: Break circle
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Insert at end
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    printf("Original List:\n");
    printList(head);

    int k = 2;
    head = rotateRight(head, k);

    printf("After Rotating by %d places:\n", k);
    printList(head);

    return 0;
}