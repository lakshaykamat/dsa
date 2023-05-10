#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
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
void deleteFirstNode(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("Error: The list is already empty.\\n");
        return;
    }

    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
}
void deleteAtIndex(struct Node** headRef, int index) {
    if (*headRef == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    
    // Handle the special case of deleting the first node
    if (index == 0) {
        struct Node* temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return;
    }
    
    // Traverse the list to find the node before the deletion point
    struct Node* currentNode = *headRef;
    for (int i = 0; i < index - 1 && currentNode != NULL; i++) {
        currentNode = currentNode->next;
    }
    
    // Handle the case where the index is out of range
    if (currentNode == NULL || currentNode->next == NULL) {
        printf("Error: Index out of range\n");
        return;
    }
    
    // Delete the node at the given index
    struct Node* temp = currentNode->next;
    currentNode->next = temp->next;
    free(temp);
}
void deleteLastNode(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    
    // Handle the special case of a single node in the list
    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        return;
    }
    
    // Traverse the list to find the second-to-last node
    struct Node* currentNode = *headRef;
    while (currentNode->next->next != NULL) {
        currentNode = currentNode->next;
    }
    
    // Delete the last node
    struct Node* lastNode = currentNode->next;
    currentNode->next = NULL;
    free(lastNode);
}
void deleteByElement(struct Node** headRef, int data) {
    if (*headRef == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    
    // Handle the special case of the element being in the first node
    if ((*headRef)->data == data) {
        struct Node* temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return;
    }
    
    // Traverse the list to find the node before the node to be deleted
    struct Node* currentNode = *headRef;
    while (currentNode->next != NULL && currentNode->next->data != data) {
        currentNode = currentNode->next;
    }
    
    // Handle the case where the element is not found
    if (currentNode->next == NULL) {
        printf("Error: Element not found\n");
        return;
    }
    
    // Delete the node with the given element
    struct Node* temp = currentNode->next;
    currentNode->next = temp->next;
    free(temp);
}

int main(){
    struct Node* head = createNode(2);
    struct Node* second = createNode(4);
    struct Node* third = createNode(6);
    struct Node* fourth = createNode(8);
    struct Node* fifth = createNode(10);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // deleteFirstNode(&head);
    // deleteAtIndex(&head,3);
    // deleteLastNode(&head);
    // deleteByElement(&head,8);
    printList(head);
    return 0;
}