#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to check if a binary tree is a binary search tree
bool isBinarySearchTree(struct Node* root, int min, int max) {
    if (root == NULL) {
        return true;
    }

    if (root->data < min || root->data > max) {
        return false;
    }
    
    return isBinarySearchTree(root->left, min, root->data - 1) &&
           isBinarySearchTree(root->right, root->data + 1, max);
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 5);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    

    if (isBinarySearchTree(root, INT_MIN, INT_MAX)) {
        printf("The binary tree is a binary search tree.\n");
    } else {
        printf("The binary tree is not a binary search tree.\n");
    }

    return 0;
}
