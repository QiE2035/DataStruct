#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief 数组最大值
 */
#define MAX_SIZE 1024

/**
 * @brief 数据项类型
 */
typedef int DataType;

/**
 * @brief 数据表结构
 */
typedef struct SeqList
{
    DataType data[MAX_SIZE];
    int last;
} SeqList;

/**
 * @brief 初始化列表
 *
 * @param L 列表指针
 */
void initList(SeqList *L)
{
    L->last = -1;
}

/**
 * @brief 取表的长度
 *
 * @param L 列表指针
 * 
 * @return int 列表长度
 */
int lengthList(SeqList *L)
{
    return L->last + 1;
}

/**
 * @brief 取表中一项
 *
 * @param L 列表指针
 * @param i 项的位置
 * 
 * @return DataType 项的值
 */
DataType getElem(SeqList *L, int i)
{
    if (i > L->last + 1 || i < 1)
    {
        fputs("[ERROR] getElem(): 数组下标越界!\n", stderr);
        return 0;
    }
    return L->data[i - 1];
}

/**
 * @brief 找值的位置
 *
 * @param L 列表指针
 * @param x 查找的值
 * 
 * @return int 项的位置
 * 
 * @retval -1 未找到
 */
int locateElem(SeqList *L, DataType x)
{
    for (int i = 0; i <= L->last; i++)
        if (L->data[i] == x)
            return i + 1;
    return -1;
}

/**
 * @brief 向表插入项
 *
 * @param L 列表指针
 * @param i 项的位置
 * @param x 插入的值
 * 
 * @retval true 成功
 * @retval false 失败
 */
bool insertElem(SeqList *L, int i, DataType x)
{
    if (L->last == MAX_SIZE - 1)
    {
        fputs("[ERROR] insertElem(): 数组已满!\n", stderr);
        return false;
    }
    if (i < 1 || i > L->last + 2)
    {
        fputs("[ERROR] insertElem(): 插入位置不正确!\n", stderr);
        return false;
    }
    for (int j = 0; j >= i - 1; j--)
        L->data[j + 1] = L->data[j];
    L->data[i - 1] = x;
    L->last++;
    return true;
}

/**
 * @brief 输出表数据
 *
 * @param L 列表指针
 */
void printList(SeqList *L)
{
    printf("当前数据: [");
    for (int i = 1; i <= L->last + 1; i++)
        printf("%d, ", getElem(L, i));
    if (L->last >= 0)
        puts("\b\b \b]");
    else
        puts("]");
}

/**
 * @brief 删除表一项
 *
 * @param L 列表指针
 * @param i 删除位置
 * 
 * @retval true 成功
 * @retval false 失败
 */
bool deleteElem(SeqList *L, int i)
{
    if (i < 1 || i > L->last + 1)
    {
        fputs("[ERROR] deleteElem(): 删除位置不正确!\n", stderr);
        return false;
    }
    for (int j = i - 1; j <= L->last; j++)
        L->data[j] = L->data[j + 1];
    L->last--;
    return true;
}

/**
 * @brief 主函数, 测试用
 *
 * @param argc 参数数量
 * @param argv 参数数组
 * 
 * @return int 执行结果
 */
int main(int argc, char const *argv[])
{
    SeqList SL, *L = &SL;
    puts("初始化表");
    initList(L);
    putchar('\n');

    printf("列表长度: %d\n", lengthList(L));
    putchar('\n');

    for (int i = 1; i <= 10; i++)
    {
        printf("插入数据: %d\n", i);
        insertElem(L, i, i);
    }
    putchar('\n');

    printf("列表长度: %d\n", lengthList(L));
    putchar('\n');

    for (int i = 1; i <= 10; i++)
        printf("读取数据: %d: %d\n", i, getElem(L, i));
    putchar('\n');

    for (int i = 1; i <= 10; i++)
        printf("查找数据: %d: %d\n", i, locateElem(L, i));
    putchar('\n');

    for (int i = 5; i >= 1; i--)
    {
        printf("删除数据: %d\n", i);
        deleteElem(L, i);
        printList(L);
    }

    return 0;
}
