#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}


struct Node* build(int arr[], int n) {
    if (arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* q[1000];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = q[f++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }
    return root;
}


int mirror(struct Node* a, struct Node* b) {
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;

    return (a->val == b->val) &&
           mirror(a->left, b->right) &&
           mirror(a->right, b->left);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = build(arr, n);

    if (root == NULL || mirror(root->left, root->right))
        printf("YES");
    else
        printf("NO");

    return 0;
}