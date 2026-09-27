#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct QueueNode {
    ElementType data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* initQueue(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->next = NULL;
    node->data = 0; 
    Q->front =node;
    Q->rear = node;
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

// 入队
void equeue(Queue* Q, ElementType e) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = e;
    node->next = NULL;
    Q->rear->next = node;
    Q->rear = node;
}

// 出队
int dequeue(Queue* Q, ElementType* e) {
    QueueNode* node = Q->front->next;
    *e = node->data;
    Q->front->next = node->next;
    if (Q->rear == node) {
        Q->rear = Q->front;
    }
    free(node);
    return 1; // 出队成功
}

// 获取队头元素
ElementType getFront(Queue* Q) {
    if (Q->front == Q->rear) {
        printf("队列为空，无法获取队头元素\n");
        return -1; // 队列为空
    }
    return Q->front->next->data;
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
    for (int i = 0; i < 5; i++) {
        dequeue(Q, &e);
        printf("出队元素: %d\n", e);
    }

    // 获取队头元素
    e = getFront(Q);
    if (e != -1) {
        printf("队头元素: %d\n", e);
    }

    return 0;
}