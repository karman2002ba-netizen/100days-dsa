// Construct a binary tree from given inorder and postorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

// Define TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to build tree
struct TreeNode* buildTreeHelper(int* inorder, int inStart, int inEnd,
                                 int* postorder, int postStart, int postEnd) {

    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    int rootVal = postorder[postEnd];

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    int k;
    for (k = inStart; k <= inEnd; k++) {
        if (inorder[k] == rootVal)
            break;
    }

    int leftSize = k - inStart;

    root->left = buildTreeHelper(inorder, inStart, k - 1,
                                 postorder, postStart, postStart + leftSize - 1);

    root->right = buildTreeHelper(inorder, k + 1, inEnd,
                                  postorder, postStart + leftSize, postEnd - 1);

    return root;
}

// Print inorder (to verify)
void printInorder(struct TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// Driver code
int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};

    int n = 5;

    struct TreeNode* root = buildTreeHelper(inorder, 0, n-1,
                                            postorder, 0, n-1);

    printf("Inorder of constructed tree: ");
    printInorder(root);

    return 0;
}