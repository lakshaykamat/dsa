#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void init(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue element.\n");
        return;
    }

    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return;
    }

    Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        // Queue became empty after dequeueing the only element
        queue->rear = NULL;
    }

    free(temp);
}

int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot retrieve front element.\n");
        return -1; // Return a default value when there is an error
    }

    return queue->front->data;
}

int main() {
    Queue queue;
    init(&queue);

    enqueue(&queue, 2);
    enqueue(&queue, 4);
    enqueue(&queue, 6);

    printf("Front element: %d\n", front(&queue));
    dequeue(&queue);
    printf("Front element after dequeue: %d\n", front(&queue));

    return 0;
}
