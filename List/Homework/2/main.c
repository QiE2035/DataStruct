#include <stdio.h>

#include "LinkList.h"

/**
 * @brief 查找最大的节点, 若重复则取第一次
 *
 * @param L 链表指针
 * @return LinkList* 最大节点指针
 */
LinkList *findMaxNode(LinkList *L)
{
    LinkList *maxNode = L;
    L = L->next;

    while (L)
    {
        if (L->data > maxNode->data)
            maxNode = L;
        L = L->next;
    }

    return maxNode;
}

/**
 * @brief 读入待插入数据
 *
 * @return DataType 待插入数据
 */
DataType input()
{
    DataType x = 0;
    printf("请输入待插入数据: ");
    scanf("%d", &x);
    return x;
}

/**
 * @brief 主函数
 *
 * @return int 执行结果
 */
int main()
{
    LinkList *L = createTailList();
    printJSON(L);
    insertAfterNode(findMaxNode(L), input());
    printJSON(L);
    return 0;
}
