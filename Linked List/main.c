#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* allocateMem(){
    return (struct Node*)malloc(sizeof(struct Node));
}
struct Node* createNode(int data){
    struct Node* newNode = allocateMem();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printList(struct Node* node){
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
}
void insertAtFirst(struct Node** headRef,int data){
    //creating a new node in heap
    struct Node* newNode = createNode(data);

    //pointing it's next to current head to make it first element or the new head
    newNode->next = *headRef;
    //reassigning the new head
    *headRef = newNode;
}
void insertAtIndex(struct Node** headRef, int index, int data) {
    // Create a new node with the given data
    struct Node* newNode = createNode(data);
    
    // Handle the special case of inserting at the beginning of the list
    if (index == 0) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }
    
    // Traverse the list to find the node before the insertion point
    struct Node* currentNode = *headRef;
    for (int i = 0; i < index - 1 && currentNode != NULL; i++) {
        currentNode = currentNode->next;
    }
    
    // Handle the case where the index is out of range
    if (currentNode == NULL) {
        printf("Error: Index out of range\n");
        return;
    }
    
    // Insert the new node into the list
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}
void insertAtEnd(struct Node** headRef,int data){
    struct Node* newNode = createNode(data);
    // newNode->data = data;
    // If the list is empty, the new node becomes the head
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    // Traverse the list to find the last node
    struct Node* currentNode = *headRef;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}
void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Error: Previous node cannot be NULL.\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

int main(){
    //create the nodes
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);
    //link the nodes together
    head->next = second;
    second->next=third;
    third->next=NULL;


    insertAtFirst(&head,8);
    insertAtIndex(&head,3,0);
    insertAtEnd(&head,9);
    insertAfterNode(second,12);
    printList(head);
    return 0;
}