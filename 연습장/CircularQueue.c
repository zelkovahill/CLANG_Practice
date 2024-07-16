#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct{
int items[SIZE];
int front;
int rear;
}CircularQueue;

void initQueue(CircularQueue* q){
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue* q) {
    return (q->front == (q->rear + 1) % SIZE);
}

int isEmpty(CircularQueue* q){
    return (q->front == -1);
}

void enqueue(CircularQueue* q, int value){
    if(isFull(q)){
        printf("원형 큐가 가득 찼습니다. \n");
        return;
    }

    if(isEmpty(q)){
        q->front =0;
    }

    q->rear = (q->rear+1)%100;
    q->items[q->rear] = value;
    printf("Inserted -> %d\n", value);
}

int dequeue(CircularQueue* q){
    if(isEmpty(q)){
        printf("원형 큐가 빙 비어있습니다. \n");
        return -1;
    }
    int value = q->items[q->front];

    if(q->front == q-> rear){
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front = (q->front +1) % SIZE;
    }
    return value;
}

void display(CircularQueue* q){
    if(isEmpty(q)){
        printf("원형 큐가 비어있습니다.\n");
        return;
    }

    for(int i =q->front; i<=q->rear;i++){
        printf("%d <- ", q->items[i]);
    }
  
    printf("\n");
}

int main(){
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 1);
     enqueue(&q, 2);
     enqueue(&q, 3);
     enqueue(&q, 4);
     enqueue(&q, 5);
     display(&q);
     printf("Deleted -> %d\n", dequeue(&q));
     printf("Deleted -> %d\n", dequeue(&q));
     printf("Deleted -> %d\n", dequeue(&q));
     printf("Deleted -> %d\n", dequeue(&q));
     printf("Deleted -> %d\n", dequeue(&q));

    
   
    display(&q);
}

