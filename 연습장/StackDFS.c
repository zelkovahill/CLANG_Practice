#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position* data;
    int top;
    int capacity;
} Stack;

void initStack(Stack* stack, int capacity) {
    stack->data = (Position*)malloc(capacity * sizeof(Position));
    stack->top = -1;
    stack->capacity = capacity;
}

void push(Stack* stack, Position pos) {
    if (stack->top == stack->capacity - 1) {
        stack->capacity *= 2;
        stack->data = (Position*)realloc(stack->data, stack->capacity * sizeof(Position));
    }
    stack->data[++stack->top] = pos;
}

Position pop(Stack* stack) {
    if (stack->top == -1) {
        Position invalid = {-1, -1};
        return invalid;
    }
    return stack->data[stack->top--];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void freeStack(Stack* stack) {
    free(stack->data);
}

int isSafe(int maze[ROWS][COLS], int visited[ROWS][COLS], int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 1 && visited[x][y] == 0);
}

void printPath(Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("(%d, %d) ", stack->data[i].x, stack->data[i].y);
    }
    printf("\n");
}

void mazeSolver(int maze[ROWS][COLS], int startX, int startY, int endX, int endY) {
    int visited[ROWS][COLS] = {0};
    Stack stack;
    initStack(&stack, 10);

    Position start = {startX, startY};
    push(&stack, start);
    visited[startX][startY] = 1;

    int rowNum[] = {-1, 1, 0, 0};
    int colNum[] = {0, 0, -1, 1};

    while (!isEmpty(&stack)) {
        Position pos = pop(&stack);

        if (pos.x == endX && pos.y == endY) {
            printf("Path to the exit: ");
            printPath(&stack);
            freeStack(&stack);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = pos.x + rowNum[i];
            int newY = pos.y + colNum[i];

            if (isSafe(maze, visited, newX, newY)) {
                visited[newX][newY] = 1;
                Position newPos = {newX, newY};
                push(&stack, newPos);
            }
        }
    }

    printf("No path found.\n");
    freeStack(&stack);
}

int main() {
    int maze[ROWS][COLS] = {
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1}
    };

    int startX = 0, startY = 0;
    int endX = 4, endY = 4;

    mazeSolver(maze, startX, startY, endX, endY);

    return 0;
}