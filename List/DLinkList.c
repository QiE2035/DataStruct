#include <stdio.h>

/**
 * @brief 数据类型
 *
 */
typedef int DataType;

/**
 * @brief 双向链表
 *
 */
typedef struct DNode
{
    DataType data;
    struct DNode *pre, *next;
} DLinkList;

/**
 * @brief 链接两个节点
 *
 * @param preNode 前一个节点
 * @param nextNode 后一个节点
 */
void connect(DLinkList *preNode, DLinkList *nextNode)
{
    preNode->next = nextNode;
    nextNode->pre = preNode;
}



/**
 * @brief 主函数
 *
 * @param argc 参数个数
 * @param argv 参数列表
 * @return int 运行结果
 */
int main(int argc, char const *argv[])
{

    return 0;
}
