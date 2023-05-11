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
int search(struct Node* head, int value) {
    struct Node* currentNode = head;
    int index = 0;

    while (currentNode != NULL) {
        if (currentNode->data == value) {
            return index;
        }
        currentNode = currentNode->next;
        index++;
    }

    // Value not found
    return -1;
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

    int index = search(head,10);
    if(index == -1){
        printf("Error:Element not found\n");
    }else{
        printf("Element found at index %d\n",index);
    }
    printList(head);
    return 0;
}