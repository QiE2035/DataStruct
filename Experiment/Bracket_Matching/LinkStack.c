#include <stdio.h>
#include <stdlib.h>

#include "LinkStack.h"

/**
 * @brief 初始化栈
 *
 * @return LinkStack* 栈指针, 始终为 NULL
 */
LinkStack *initStack()
{
    return NULL;
}

/**
 * @brief 判空
 *
 * @param s 栈指针
 * @return true 为空
 * @return false 不为空
 */
bool empty(LinkStack *s)
{
    return s == NULL;
}

/**
 * @brief 入栈
 *
 * @param s 栈指针
 * @param x 数据
 */
LinkStack *push(LinkStack *s, DataType x)
{
    LinkStack *p = (LinkStack *)malloc(sizeof(LinkStack));
    p->data = x;
    p->next = s;
    return p;
}

/**
 * @brief 出栈
 *
 * @param s 栈指针
 */
LinkStack *pop(LinkStack *s)
{
    LinkStack *p = s;
    s = s->next;
    free(p);
    return s;
}

/**
 * @brief 取栈顶数据
 *
 * @param s 栈指针
 * @return DataType 数据
 */
DataType top(LinkStack *s)
{
    return s->data;
}