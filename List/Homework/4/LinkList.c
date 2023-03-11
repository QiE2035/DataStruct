#include <stdio.h>
#include <stdlib.h>

#include "LinkList.h"

/**
 * @brief 初始化节点
 *
 * @param x 数据
 * @param next 下一个节点的指针
 * @return LinkList* 生成的节点
 */
LinkList *initNode(DataType x, LinkList *next)
{
    LinkList *L = (LinkList *)malloc(sizeof(LinkList));
    L->data = x;
    L->next = next;
    return L;
}

/**
 * @brief 输出链表
 *
 * @param L 链表指针
 */
void printJSON(LinkList *L)
{
    L = L->next;
    printf("当前链表内数据为: [");
    while (L)
    {
        printf("%c, ", L->data);
        L = L->next;
    }
    puts("\b\b]");
}

/**
 * @brief 尾插法建立带头节点链表
 *
 * @return LinkList*
 */
LinkList *createTailList()
{
    DataType x = 0;
    LinkList *headNode = initNode(0, NULL), *L = headNode;

    printf("请输入数据, 以回车结束: ");
    while (1)
    {
        scanf("%c", &x);
        if (x == '\n')
            break;

        L = L->next = initNode(x, NULL);
    }

    return headNode;
}

/**
 * @brief 在节点后插入
 *
 * @param n 节点
 * @param x 数据
 */
void insertAfterNode(LinkList *n, DataType x)
{
    n->next = initNode(x, n->next);
}

/**
 * @brief 删除节点
 *
 * @param preNode 前一个节点
 */
void deleteAfterNode(LinkList *preNode)
{
    LinkList *tmp = preNode->next;
    if (tmp)
    {
        preNode->next = tmp->next;
        free(tmp);
    }
}