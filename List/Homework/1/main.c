#include <stdio.h>

#include "SeqList.h"

/**
 * @brief 输入数据
 *
 * @param L 列表指针
 */
void input(SeqList *L)
{
    DataType tmp = 0;

    printf("请输入数据, 以回车结束: ");
    while (true)
    {
        scanf("%c", &tmp);
        if (tmp == '\n')
            break;
        if (!(tmp >= 'A' && tmp <= 'Z') && !(tmp >= 'a' && tmp <= 'z'))
        {
            fprintf(stderr, "[ERROR]: input(): 输入的字符不合法!\n");
            break;
        }

        if (!insertElem(L, L->last + 2, tmp))
            break;
    }
}

/**
 * @brief 转换回调
 *
 * @param x 遍历输入
 * @return DataType 转换结果
 */
DataType conv(DataType x)
{

    if (x >= 'A' && x <= 'Z')
        return x - 'A' + 'a';
    return x;
}

/**
 * @brief 主函数
 *
 * @return int 执行结果
 */
int main()
{
    SeqList list, *L = &list;
    initList(L);      // 初始化表
    input(L);         // 输入数据
    forEach(L, conv); // 遍历转换
    printList(L);     // 输出结果
    return 0;
}
