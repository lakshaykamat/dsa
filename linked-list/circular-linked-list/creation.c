#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* currentNode = head;

    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    do {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode != head);

    printf("\n");
}

int main() {
    // Create nodes
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);
    struct Node* fourth = createNode(4);

    // Connect nodes to form a circular linked list
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;


    printList(head);

    return 0;
}
