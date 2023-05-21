#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Create the nodes of the binary tree
    struct TreeNode* root = createNode(1);
    struct TreeNode* node2 = createNode(2);
    struct TreeNode* node3 = createNode(3);
    struct TreeNode* node4 = createNode(4);
    struct TreeNode* node5 = createNode(5);

    // Connect the nodes to form the tree
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;

    // Perform operations on the binary tree
    // ...

    return 0;
}
