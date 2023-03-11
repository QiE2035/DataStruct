#ifndef _SEQ_LIST_
#define _SEQ_LIST_

#include <stdbool.h>

/**
 * @brief 数组最大值
 */
#define MAX_SIZE 1024

/**
 * @brief 数据项类型
 */
typedef char DataType;

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
void initList(SeqList *L);

/**
 * @brief 取表中一项
 *
 * @param L 列表指针
 * @param i 项的位置
 *
 * @return DataType 项的值
 */
DataType getElem(SeqList *L, int i);

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
int locateElem(SeqList *L, DataType x);

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
bool insertElem(SeqList *L, int i, DataType x);

/**
 * @brief 输出表数据
 *
 * @param L 列表指针
 */
void printList(SeqList *L);

/**
 * @brief 删除表一项
 *
 * @param L 列表指针
 * @param i 删除位置
 *
 * @retval true 成功
 * @retval false 失败
 */
bool deleteElem(SeqList *L, int i);

/**
 * @brief 回调函数的定义
 *
 * @param x 遍历项
 * @return DataType 遍历结果
 */
typedef DataType (*callback)(DataType x);

/**
 * @brief 遍历数据
 *
 * @param L 列表指针
 * @param c 回调函数
 */
void forEach(SeqList *L, callback c);

#endif // _SEQ_LIST_
