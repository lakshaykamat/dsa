#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the stack
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Structure to represent the stack
typedef struct
{
    int size;
    int maxSize;
    Node *top;
} Stack;


int isEmpty(Stack *stack){
    return stack->size == 0;
}

int isFull(Stack *stack){
    return stack->size == stack->maxSize;
}


void initialize(Stack *stack, int maxSize){
    stack->top = NULL;
    stack->size = 0;
    stack->maxSize = maxSize;
}

void push(Stack *stack, int data){
    if (isFull(stack))
    {
        printf("Stack overflow! Cannot push element.\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(Stack *stack){
    if (isEmpty(stack))
    {
        printf("Stack underdflow! Cannot pop element.\n");
        return -1;
    }
    Node *temp = stack->top;
    int item = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return item;
}

int peek(Stack *stack){
    if (isEmpty(stack))
    {
        printf("Stack underdflow! Cannot peek element.\n");
        return -1;
    }

    return stack->top->data;
}

void clearStack(Stack* stack){
    printf("Clearing Elements: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
}
int main()
{
    int maxSize = 10;
    Stack stack;

    initialize(&stack,maxSize);



    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    clearStack(&stack);

    return 0;
}