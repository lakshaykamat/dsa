#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data){
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // Assign the data to the new node
    newNode->data = data;
    
    // Set the next pointer of the new node to NULL
    newNode->next = NULL;

    // Return the newly created node
    return newNode;
}

// Function to print the elements of the linked list
void printList(struct Node* node){
    while(node != NULL){
        // Print the data of the current node
        printf("%d ", node->data);
        
        // Move to the next node
        node = node->next;
    }
}

int main(){
    // Create the head node and assign it data value of 2
    struct Node* head = createNode(2);
    
    // Create the second node and assign it data value of 4
    struct Node* second = createNode(4);
    
    // Create the third node and assign it data value of 6
    struct Node* third = createNode(6);

    // Connect the nodes in the linked list
    head->next = second;
    second->next = third;

    // Print the linked list
    printList(head);

    return 0;
}
