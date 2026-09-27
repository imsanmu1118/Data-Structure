#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;
typedef struct stack
{
    ElementType data;
    struct stack* next;
} Stack;

Stack* initStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = 0; // Initialize data to 0 or any default value
    s->next = NULL;
    return s;
}

//判断栈是否为空
int isEmpty(Stack* s) {
    if (s->next == NULL) {
        printf("栈为空\n");
        return 1; // 栈为空
    } else {
        return 0; // 栈不为空
    }
}

//进栈/压栈(链表的头插法)
int push(Stack* s, ElementType e) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    if (!newNode) {
        printf("内存分配失败\n");
        return 0; // 内存分配失败
    }
    newNode->data = e;
    newNode->next = s->next;
    s->next = newNode;
    return 1; // 进栈成功
}

//出栈/弹栈(链表的头删法)
int pop(Stack* s, ElementType* e) {
    if (s->next == NULL) {
        printf("栈为空，无法出栈\n");
        return 0; // 栈为空
    }
    Stack* temp = s->next;
    *e = s->next->data;
    s->next = temp->next;
    free(temp);
    return 1; // 出栈成功
} 

//获取栈顶元素
int getTop(Stack* s, ElementType* e) {
    if (s->next == NULL) {
        printf("栈为空，无法获取栈顶元素\n");
        return 0; // 栈为空
    }
    *e = s->next->data;
    return 1; // 获取栈顶元素成功
}

int main(int argc, char* argv[]) {
    Stack* s = initStack();
    ElementType e;

    // 测试进栈
    push(s, 1);
    push(s, 2);
    push(s, 3);

    // 测试获取栈顶元素
    if (getTop(s, &e)) {
        printf("栈顶元素为: %d\n", e);
    }

    // 测试出栈
    if (pop(s, &e)) {
        printf("出栈元素为: %d\n", e);
    }

    return 0;
}