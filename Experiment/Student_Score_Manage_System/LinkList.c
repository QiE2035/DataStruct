#include <stdio.h>
#include <stdlib.h>

#include "log.h"
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
 * @brief 尾插法建立带头节点链表
 *
 * @param callback 创建回调
 *
 * @return LinkList* 创建后的头节点
 */
LinkList *createTailList(create_callback callback, bool has_hint)
{
    DataType x;
    bool is_continue = true;
    LinkList *headNode = initNode(x, NULL), *L = headNode;
    jmp_buf jb;

    while (is_continue)
    {
        if (setjmp(jb))
            break;
        else
            L = L->next = initNode(callback(&jb), NULL);

        if (has_hint)
        {
            printf("\n按回车继续, 输入 0 退出: ");
            if (is_continue = getchar() - '0')
                putchar('\n');
        }
    }

    return headNode;
}

/**
 * @brief 输出链表
 *
 * @param L 链表指针
 * @param callback 元素回调
 * @param new_line 是否换行
 */
void printList(LinkList *L, forEach_callback callback, bool new_line)
{
    putchar('[');

    while (L = L->next)
    {
        if (new_line)
            putchar('\n');

        callback(L);
        putchar(',');
    }

    printf("\b ");
    if (new_line)
        putchar('\n');
    puts("]");
}

/**
 * @brief 在节点后插入
 *
 * @param n 节点
 * @param x 数据
 */
void insertAfterNode(LinkList *n, DataType x)
{
    if (!n)
    {
        log_err("节点为 NULL, 插入失败!");
        return;
    }
    n->next = initNode(x, n->next);
}

/**
 * @brief 删除节点
 *
 * @param n 前一个节点
 */
void deleteAfterNode(LinkList *n)
{
    if (!n)
    {
        log_err("节点为 NULL, 删除失败!");
        return;
    }
    LinkList *tmp = n->next;

    if (tmp)
    {
        n->next = tmp->next;
        free(tmp);
    }
}

/**
 * @brief 按索引获取节点
 *
 * @param L 链表指针
 * @param i 索引
 * @return LinkList* 获得的节点
 */
LinkList *getNode(LinkList *L, int i)
{
    if (i >= 0)
        for (int tmp = 0; L; tmp++)
        {
            if (tmp >= i)
                return L;
            L = L->next;
        }

    log_err("索引不合法!");
    return NULL;
}

/**
 * @brief 按条件查找节点
 *
 * @param L 链表指针
 * @param callback 条件回调
 * @param has_head 包括头节点
 * @return LinkList* 找到的节点
 */
LinkList *findNode(LinkList *L, find_callback callback, bool has_head)
{
    if (!has_head)
        L = L->next;

    while (L)
    {
        if (callback(L))
            return L;

        L = L->next;
    }

    log_warn("未找到节点!");
    return NULL;
}

/**
 * @brief 遍历节点
 * 
 * @param L 链表指针
 * @param callback 遍历回调
 * @param has_head 包括头节点
 */
void forEach(LinkList *L, forEach_callback callback, bool has_head)
{
    if (!has_head)
        L = L->next;

    while (L)
    {
        callback(L);
        L = L->next;
    }
}