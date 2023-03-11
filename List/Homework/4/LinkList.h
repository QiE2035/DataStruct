#ifndef _LINK_LIST_
#define _LINK_LIST_

/**
 * @brief 数据类型
 *
 */
typedef char DataType;

/**
 * @brief 节点结构
 *
 */
typedef struct Node
{
    DataType data;
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
 * @brief 输出链表
 *
 * @param L 链表指针
 */
void printJSON(LinkList *L);

/**
 * @brief 尾插法建立带头节点链表
 *
 * @return LinkList*
 */
LinkList *createTailList();

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
 * @param preNode 前一个节点
 */
void deleteAfterNode(LinkList *preNode);

#endif // _LINK_LIST_
