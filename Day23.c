#include <stdio.h>
#include <stdlib.h>

// Structure define
struct Node {
    int data;
    struct Node* next;
};

// New node create karne ka function
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Merge function
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

// Print function
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // First sorted list: 1 -> 3 -> 5
    struct Node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    // Second sorted list: 2 -> 4 -> 6
    struct Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);

    printf("List 1: ");
    printList(l1);

    printf("List 2: ");
    printList(l2);

    struct Node* merged = mergeSortedLists(l1, l2);

    printf("Merged List: ");
    printList(merged);

    return 0;
}