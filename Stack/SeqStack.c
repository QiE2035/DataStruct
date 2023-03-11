#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 栈最大大小
 *
 */
#define MAXSIZE 1024
/**
 * @brief 数据类型
 *
 */
typedef int DataType;
/**
 * @brief 栈结构体
 *
 */
typedef struct {
    DataType data[MAXSIZE];
    int top;
} SeqStack;

/**
 * @brief 初始化栈
 *
 * @return SeqStack* 栈指针
 */
SeqStack *initSeqStack() {
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

/**
 * @brief 判空
 *
 * @param s 栈指针
 * @return true 为空
 * @return false 不为空
 */
bool empty(SeqStack *s) {
    if (s->top == -1)
        return true;
    else
        return false;
}

/**
 * @brief 入栈
 *
 * @param s 栈指针
 * @param x 数据
 * @return true 成功
 * @return false 失败
 */
bool push(SeqStack *s, DataType x) {}

DataType top() {}

void pop(SeqStack *s) {
    if (empty(s)) {
    } else
        s->top--;
}