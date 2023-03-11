#include <stdio.h>

#include "LinkList.h"

/**
 * @brief 拆分为三种表
 * 
 * @param L 表指针
 * @param letterL 字母表指针
 * @param numberL 数字表指针
 * @param symbolL 符号表指针
 */
void split3(LinkList *L,
            LinkList *letterL,
            LinkList *numberL,
            LinkList *symbolL)
{
    DataType tmp = 0;
    LinkList *tmpL = L = L->next;
    while (L)
    {
        tmp = L->data;

        if (('A' <= tmp && tmp <= 'Z') ||
            ('a' <= tmp && tmp <= 'z'))
        {
            letterL = letterL->next = L;
        }
        else if ('0' <= tmp && tmp <= '9')
            numberL = numberL->next = L;
        else
            symbolL = symbolL->next = L;

        tmpL = L->next;
        L->next = NULL;
        L = tmpL;
    }
}

/**
 * @brief 主函数
 *
 * @return int 执行结果
 */
int main()
{
    LinkList *L = createTailList(),
             *letterL = initNode(0, NULL),
             *numberL = initNode(0, NULL),
             *symbolL = initNode(0, NULL);

    printJSON(L);
    split3(L, letterL, numberL, symbolL);
    puts("字母表:");
    printJSON(letterL);
    puts("数字表:");
    printJSON(numberL);
    puts("符号表:");
    printJSON(symbolL);
    
    return 0;
}
