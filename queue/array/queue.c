#include <stdio.h>
#define SIZE 10
typedef struct{
    int items[SIZE];
    int front;
    int back;
}Queue;
void init(Queue* queue){
    queue->front = -1;
    queue->back = -1;
}
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

int isFull(Queue* queue) {
    return queue->back == SIZE -1;
}

void enqueue(Queue* queue,int data){
    if(isFull(queue)){
        return;
    }
    if(isEmpty(queue)){
        queue->front = 0;
    }

    queue->items[++queue->back] = data;
}

void dequeue(Queue* queue){
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return;
    }
    if (queue->front == queue->back) {
        // Last element in the queue
        queue->front = -1;
        queue->back = -1;
    } else {
        queue->front = ++queue->front;
    }

}

int peek(Queue* queue){
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot retrieve front element.\n");
        return -1; // Return a default value when there is an error
    }
    return queue->items[queue->front];
}
int main(){
    Queue q1;
    init(&q1);
    enqueue(&q1,2);
    enqueue(&q1,4);
    enqueue(&q1,6);
    enqueue(&q1,8);
    printf("%d ",peek(&q1));
    dequeue(&q1);
    printf("%d ",peek(&q1));
    return 0;
}