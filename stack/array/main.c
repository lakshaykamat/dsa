#include <stdio.h>
#include <stdlib.h>

// Structure to represent the stack
typedef struct {
    int* items;
    int top;
    int maxSize;
} Stack;

// Initialize the stack with a given initial size
void initialize(Stack* stack, int maxSize) {
    stack->items = (int*)malloc(sizeof(int) * maxSize);
    stack->top = -1;
    stack->maxSize = maxSize;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->maxSize - 1;
}

// Push an element onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push element\n");
    }
    
    stack->top++;
    stack->items[stack->top] = item;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop element.\n");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}

// Peek the top element of the stack without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    } else {
        return stack->items[stack->top];
    }
}
void clearStack(Stack* stack){
    while(!isEmpty(stack)){
        printf("%d ",pop(stack));
    }
}

int main() {
    Stack stack;
    initialize(&stack, 3);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40); // Exceeding initial size, stack will resize dynamically

    printf("Top element: %d\n", peek(&stack));

    printf("Elements: ");
    clearStack(&stack);
    printf("\n");

    free(stack.items); // Free the dynamically allocated memory

    return 0;
}
