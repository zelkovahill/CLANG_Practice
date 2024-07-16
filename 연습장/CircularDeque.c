#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct{
    int items[SIZE];
    int front;
    int rear;
}CircularDeque;

void initDeque(CircularDeque* dq){
    dq->front = -1;
    dq->rear = -1;
}

int isFull(CircularDeque* dq) {
    return ((dq->front == 0 && dq->rear == SIZE - 1) || (dq->front == dq->rear + 1));
}


int isEmpty(CircularDeque* dq){
    return (dq->front == -1);
}

void insertFront(CircularDeque* dq, int value) {
    if (isFull(dq)) {
        printf("덱이 가득 찼습니다.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = SIZE - 1;
    } else {
        dq->front--;
    }
    dq->items[dq->front] = value;
    printf("Front에 %d 삽입\n", value);
}

void insertRear(CircularDeque* dq, int value){
    if(isFull(dq)){
        printf("덱이 가득 찼습니다.\n");
        return;
    }
    if(isEmpty(dq)){
        dq->front = dq->rear = 0;
    }
    else if(dq->rear == SIZE - 1){
        dq->rear = 0;
    }
    else{
        dq->rear++;
    }
    dq->items[dq->rear] = value;
    printf("Rear에 %d 삽입 \n", value);
}

void deleteFront(CircularDeque* dq){
    if(isEmpty(dq)){
        printf("덱이 비어있습니다.\n");
        return;
    }
    printf("Front에서 %d 삭제\n", dq->items[dq->front]);
    if(dq->front == dq ->rear){
        dq->front = dq->rear = -1;
    }
    else if (dq->front == SIZE - 1) {
        dq->front = 0;
    }
    else{
        dq->front++;
    }
}

void deleteRear(CircularDeque* dq){
    if(isEmpty(dq)){
        printf("덱이 비어있습니다.\n");
        return;
    }
    printf("Rear에서 %d 삭제\n",dq->items[dq->rear]);
    if(dq->front == dq->rear){
        dq->front = dq ->rear = -1;
    }
    else if(dq->rear==0){
        dq->rear = SIZE-1;
    }
    else{
        dq->rear--;
    }

}

int getFront(CircularDeque* dq){
if(isEmpty(dq)){
        printf("덱이 비어있습니다.\n");
        return -1;
    }
    
    return dq->items[dq->front];
}

int getRear(CircularDeque* dq){
    if(isEmpty(dq)||dq->rear <0){
        printf("덱이 비어있습니다.\n");
        return -1;
    }
    return dq->items[dq->rear];
}

void display(CircularDeque* dq) {
    if (isEmpty(dq)) {
        printf("덱이 비어 있습니다.\n");
        return;
    }
    printf("덱의 내용: ");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d ", dq->items[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", dq->items[i]);
}


int main(){

    CircularDeque dq;
    initDeque(&dq);

    insertFront(&dq, 1);
    insertFront(&dq, 2);
    insertRear(&dq, 3);
    insertRear(&dq, 4);

    display(&dq);

    printf("Front: %d\n", getFront(&dq));
    printf("Rear: %d\n", getRear(&dq));

    deleteFront(&dq);
    deleteRear(&dq);
    display(&dq);


    return 0;
}



