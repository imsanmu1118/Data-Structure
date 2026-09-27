#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef int ElementType;


typedef struct
{
    ElementType *data;
    int front;
    int rear;
} Queue;

Queue* initQueue() {
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->data = (ElementType*)malloc(MAX_SIZE * sizeof(ElementType));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

// 判断队列是否为空
int isEmpty(Queue* Q) {
    if (Q->front == Q->rear) {
        printf("队列为空\n");
        return 1; // 队列为空
    } else {
        return 0; // 队列不为空
    }
}  

//入队
int equeue(Queue* Q, ElementType e){

    if ((Q->rear+1) % MAX_SIZE == Q->front) {
        printf("队列已满，无法入队\n");
        return 0; // 队列已满
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_SIZE; // 循环队列
    return 1; // 入队成功
}

//出队
int dequeue(Queue* Q, ElementType* e) {
    if (Q->front == Q->rear) {
        printf("队列为空，无法出队\n");
        return 0; // 队列为空
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_SIZE; // 循环队列
    return 1; // 出队成功
}

int main(int argc, char* argv[]) {
    Queue* Q = initQueue();
    ElementType e;

    // 测试入队
    for (int i = 0; i < 10; i++) {
        equeue(Q, i);
        printf("入队元素: %d\n", i);
    }

    // 测试出队
    while (!isEmpty(Q)) {
        dequeue(Q, &e);
        printf("出队元素: %d\n", e);
    }

    free(Q->data);
    free(Q);
    return 0;
}

