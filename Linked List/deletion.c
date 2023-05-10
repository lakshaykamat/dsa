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
int main(){
    struct Node* head = createNode(2);
    struct Node* second = createNode(4);
    struct Node* third = createNode(6);
    head->next = second;
    second->next = third;
    printList(head);
    return 0;
}