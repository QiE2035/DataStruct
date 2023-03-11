#include <stdio.h>

#include "LinkList.h"

/**
 * @brief 删除偶数
 *
 * @param L 链表指针
 */
void deleteEven(LinkList *L)
{
    puts("删除偶数节点");
    
    while (L->next)
    {
        if (L->next->data % 2 == 0)
            deleteAfterNode(L);
        L = L->next;
    }
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
    deleteEven(L);
    printJSON(L);
    return 0;
}
