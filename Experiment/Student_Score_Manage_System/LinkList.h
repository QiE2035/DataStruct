#ifndef _LINK_LIST_
#define _LINK_LIST_

#include <stdbool.h>
#include <setjmp.h>

/**
 * @brief 数据类型
 *
 */
typedef struct Student
{
    // 学号
    int sno;
    // 姓名
    char name[10];
    // 成绩
    int score;
} DataType;

/**
 * @brief 节点结构
 *
 */
typedef struct Node
{
    // 数据域
    DataType data;
    // 指针域
    struct Node *next;
} LinkList;

/**
 * @brief 初始化节点
 *
 * @param x 数据
 * @param next 下一个节点的指针
 * @return LinkList* 生成的节点
 */
LinkList *initNode(DataType x, LinkList *next);

/**
 * @brief 在节点后插入
 *
 * @param n 节点
 * @param x 数据
 */
void insertAfterNode(LinkList *n, DataType x);

/**
 * @brief 删除节点
 *
 * @param n 前一个节点
 */
void deleteAfterNode(LinkList *n);

/**
 * @brief 遍历回调
 *
 * @param 遍历元素
 */
typedef void (*forEach_callback)(LinkList *L);

/**
 * @brief 创建回调
 *
 * @return 创建数据
 */
typedef DataType (*create_callback)(jmp_buf *jb);

/**
 * @brief 尾插法建立带头节点链表
 *
 * @param callback 创建回调
 *
 * @return LinkList* 创建后的头节点
 */
LinkList *createTailList(create_callback callback, bool has_hint);

/**
 * @brief 输出 JSON
 *
 * @param L 链表指针
 * @param callback 元素回调
 * @param new_line 是否换行
 */
void printList(LinkList *L, forEach_callback callback, bool new_line);

/**
 * @brief 查找回调
 *
 * @param n 遍历节点
 *
 * @retval true 条件成立
 * @retval false 条件不成立
 */
typedef bool (*find_callback)(LinkList *n);

/**
 * @brief 按索引获取节点
 *
 * @param L 链表指针
 * @param i 索引
 * @return LinkList* 获得的节点
 */
LinkList *getNode(LinkList *L, int i);

/**
 * @brief 按条件查找节点
 *
 * @param L 链表指针
 * @param callback 条件回调
 * @param has_head 包括头节点
 * @return LinkList* 找到的节点
 */
LinkList *findNode(LinkList *L, find_callback callback, bool has_head);

/**
 * @brief 遍历节点
 *
 * @param L 链表指针
 * @param callback 遍历回调
 * @param has_head 包括头节点
 */
void forEach(LinkList *L, forEach_callback callback, bool has_head);

#endif // _LINK_LIST_
