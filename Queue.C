#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef int ElementType;

// typedef struct {
//     ElementType data[MAX_SIZE];
//     int front;
//     int rear;
// } Queue;

typedef struct
{
    ElementType *data;
    int front;
    int rear;
} Queue;

// // 初始化队列
// void initQueue(Queue* Q) {
//     Q->front = 0;
//     Q->rear = 0;
// }

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

//出队
ElementType dequeue(Queue* Q) {
    if (isEmpty(Q)) {
        printf("队列为空，无法出队\n");
        return -1; // 队列为空
    }
    ElementType e = Q->data[Q->front];
    Q->front++;
    // Q->front = (Q->front + 1) % MAX_SIZE; // 循环队列
    return e; // 出队成功
}

//调整队列
int queueFull(Queue* Q)
{
    if(Q->front>0)
    {
        int difference = Q->front;
        for(int i = Q->front; i <= Q->rear; ++i)
        {
            Q->data[i - difference] = Q->data[i];
        }
        Q->front = 0;
        Q->rear -= difference;
        return 1;
    }
    else
    {
        printf("队列已满，无法入队\n");
        return 0; // 队列已满
    }
}

//入队
int enqueue(Queue* Q, ElementType e) {
    if (Q->rear >= MAX_SIZE) {
        if (!queueFull(Q)) {
            return 0; // 队列已满
        }
    }
    Q->data[Q->rear] = e;
    Q->rear++;
    return 1; // 入队成功
}

//获取队头元素
ElementType getFront(Queue* Q) {
    if (isEmpty(Q)) {
        printf("队列为空，无法获取队头元素\n");
        return -1; // 队列为空
    }
    return Q->data[Q->front]; // 返回队头元素
}

int main(int argc, char* argv[]) {
    Queue* Q = initQueue();
    ElementType e;

    // 测试入队
    for (int i = 0; i < 5; i++) {
        enqueue(Q, i);
        printf("入队元素: %d\n", i);
    }

    // 测试获取队头元素
    e = getFront(Q);
    if (e != -1) {
        printf("队头元素: %d\n", e);
    }

    // 测试出队
    while (!isEmpty(Q)) {
        e = dequeue(Q);
        if (e != -1) {
            printf("出队元素: %d\n", e);
        }
    }

    return 0;
}