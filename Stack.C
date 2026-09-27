#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef int ElementType;

// 初始化
// typedef struct {
//     ElementType data[MAX_SIZE];
//     int top;
// } Stack;

// void initStack(Stack* s) {
//     s->top = -1;
// }

typedef struct
{
    ElementType *data;
    int top;
} Stack;

Stack* initStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (ElementType*)malloc(MAX_SIZE * sizeof(ElementType));
    s->top = -1;
    return s;
}

//判断栈是否为空
int isEmpty(Stack* s) {
    if (s->top == -1) {
        printf("栈为空\n");
        return 1; // 栈为空
    } else {
        return 0; // 栈不为空
    }
}

//进栈/压栈
int push(Stack* s ,ElementType e)
{
    if (s->top == MAX_SIZE - 1) {
        printf("栈已满，无法进栈\n");
        return 0; // 栈已满
    }  
    s->top++;
    s->data[s->top] = e;
    return 1; // 进栈成功
}

//出栈/弹栈
int pop(Stack* s, ElementType* e) {
    if (s->top == -1) {
        printf("栈为空，无法出栈\n");
        return 0; // 栈为空
    }
    *e = s->data[s->top];
    s->top--;
    return 1; // 出栈成功
}

//获取栈顶元素
int getTop(Stack* s, ElementType* e) {
    if (s->top == -1) {
        printf("栈为空，无法获取栈顶元素\n");
        return 0; // 栈为空
    }
    *e = s->data[s->top];
    return 1; // 获取栈顶元素成功
}

int main(int argc, char* argv[]) {
    Stack* s = initStack();
    ElementType e;

    // 测试进栈
    push(s, 10);
    push(s, 20);
    push(s, 30);

    // 测试获取栈顶元素
    if (getTop(s, &e)) {
        printf("栈顶元素: %d\n", e);
    }

    // 测试出栈
    if (pop(s, &e)) {
        printf("出栈元素: %d\n", e);
    }

    // 再次获取栈顶元素
    if (getTop(s, &e)) {
        printf("栈顶元素: %d\n", e);
    }

    // 清理内存
    free(s->data);
    free(s);

    return 0;
}
