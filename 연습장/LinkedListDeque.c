#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct LinkedListDeque {
    Node* front;
    Node* rear;
} LinkedListDeque;

void init(LinkedListDeque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

int isEmpty(LinkedListDeque* deque) {
    return (deque->front == NULL);
}

void insertFront(LinkedListDeque* deque, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = deque->front;

    if (isEmpty(deque)) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }

    deque->front = newNode;
    printf("Front에 %d 삽입\n", value);
}

void insertRear(LinkedListDeque* deque, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (isEmpty(deque)) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }

    deque->rear = newNode;
    printf("Rear에 %d 삽입\n", value);
}

void deleteFront(LinkedListDeque* deque) {
    if (isEmpty(deque)) {
        printf("덱이 비어 있습니다.\n");
        return;
    }

    Node* temp = deque->front;
    printf("Front에서 %d 삭제\n", temp->data);

    deque->front = deque->front->next;

    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(temp);
}

void deleteRear(LinkedListDeque* deque) {
    if (isEmpty(deque)) {
        printf("덱이 비어 있습니다.\n");
        return;
    }

    Node* temp = deque->rear;
    printf("Rear에서 %d 삭제\n", temp->data);

    deque->rear = deque->rear->prev;

    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(temp);
}

int getFront(LinkedListDeque* deque) {
    if (isEmpty(deque)) {
        printf("덱이 비어 있습니다.\n");
        return -1;
    }
    return deque->front->data;
}

int getRear(LinkedListDeque* deque) {
    if (isEmpty(deque)) {
        printf("덱이 비어 있습니다.\n");
        return -1;
    }
    return deque->rear->data;
}

void display(LinkedListDeque* deque) {
    if (isEmpty(deque)) {
        printf("덱이 비어 있습니다.\n");
        return;
    }

    Node* current = deque->front;
    printf("덱 내용: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedListDeque dq;
    init(&dq);

    insertFront(&dq, 10);
    insertFront(&dq, 20);
    insertRear(&dq, 30);
    insertRear(&dq, 40);

    display(&dq);

    printf("Front: %d\n", getFront(&dq));
    printf("Rear: %d\n", getRear(&dq));

    deleteFront(&dq);
    deleteRear(&dq);

    display(&dq);

    return 0;
}