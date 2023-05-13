#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;
    int size;
    int maxSize;
} Stack;

// Initialize stack
void initialize(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
    stack->maxSize = MAX_SIZE;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->size == 0;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->size == stack->maxSize;
}

// Push an element into the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push element.\n");
        return;
    }

    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }

    Node* poppedNode = stack->top;
    int poppedData = poppedNode->data;
    stack->top = poppedNode->next;
    free(poppedNode);
    stack->size--;

    return poppedData;
}

// Get the top element of the stack without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }

    return stack->top->data;
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6); // Exceeds the maximum size

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    if (isEmpty(&stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    return 0;
}