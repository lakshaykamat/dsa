#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* currentNode = head;

    if (head == NULL) {
        printf("Doubly linked list is empty.\n");
        return;
    }

    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Create nodes for the doubly linked list
    head = createNode(1);
    second = createNode(2);
    third = createNode(3);

    // Connect the nodes to form the doubly linked list
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // Print the doubly linked list
    printf("Doubly Linked List: ");
    printList(head);

    // Free the allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
