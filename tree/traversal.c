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

// Inorder traversal: Left -> Root -> Right
void inorderTraversal(struct TreeNode* node) {
    if (node == NULL) return;

    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

// Preorder traversal: Root -> Left -> Right
void preorderTraversal(struct TreeNode* node) {
    if (node == NULL) return;

    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Postorder traversal: Left -> Right -> Root
void postorderTraversal(struct TreeNode* node) {
    if (node == NULL) return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
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
    /*
        1
       / \
      2   3
    /  \
   4    5
    */
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
