#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 数据类型
 *
 */
typedef int DataType;
/**
 * @brief 栈结构体
 *
 */
typedef struct Node {
    DataType data;
    struct Node *next;
} LinkStack;

/**
 * @brief 初始化栈
 *
 * @return LinkStack* 栈指针, 始终为 NULL
 */
LinkStack *initStack() { return NULL; }

/**
 * @brief 判空
 *
 * @param s 栈指针
 * @return true 为空
 * @return false 不为空
 */
bool empty(LinkStack *s) {
    if (s == NULL)
        return true;
    else
        return false;
}

/**
 * @brief 入栈
 *
 * @param s 栈指针
 * @param x 数据
 */
LinkStack *push(LinkStack *s, DataType x) {
    LinkStack *p;
    p = (LinkStack *)malloc(sizeof(LinkStack));
    p->data = x;
    p->next = s;
    return p;
}

/**
 * @brief 出栈
 *
 * @param s 栈指针
 */
LinkStack *pop(LinkStack *s) {
    LinkStack *p = s;
    s = s->next; // 没意义？
    free(p);
    return s;
}

/**
 * @brief 取栈顶数据
 *
 * @param s 栈指针
 * @return DataType 数据
 */
DataType top(LinkStack *s) { return s->data; }

/**
 * @brief 输出栈内容
 *
 * @param s 栈指针
 */
void printStack(LinkStack *s) {
    printf("当前栈内容: [");
    while (s != NULL) {
        printf("%d, ", s->data);
        s = s->next;
    }
    puts("]");
}