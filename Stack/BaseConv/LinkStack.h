#ifndef _LINK_STACK_
#define _LINK_STACK_

#include <stdbool.h>

/**
 * @brief 数据类型
 *
 */
typedef char DataType;

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
LinkStack *initStack();

/**
 * @brief 判空
 *
 * @param s 栈指针
 * @return true 为空
 * @return false 不为空
 */
bool empty(LinkStack *s);

/**
 * @brief 入栈
 *
 * @param s 栈指针
 * @param x 数据
 */
LinkStack *push(LinkStack *s, DataType x);

/**
 * @brief 出栈
 *
 * @param s 栈指针
 */
LinkStack *pop(LinkStack *s);

/**
 * @brief 取栈顶数据
 *
 * @param s 栈指针
 * @return DataType 数据
 */
DataType top(LinkStack *s);

/**
 * @brief 输出栈内容
 *
 * @param s 栈指针
 */
void printStack(LinkStack *s);

#endif // _LINK_STACK_
