/**
 * @file BiTree.c
 * @author 杜思维 (计算机212-15)
 * @brief 二叉链表 (递归法)
 * @version 0.1
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 数据类型定义
 *
 */
typedef char DataType;

/**
 * @brief 二叉链表节点类型定义
 *
 */
typedef struct Node {
    DataType data;
    struct Node *lchild, *rchild;
} BiTree;

/**
 * @brief 二叉链表指针，设为全局方便断点调试
 *
 */
BiTree *gT;

/**
 * @brief 创建二叉链表
 *
 * @return BiTree* 二叉链表根节点指针
 */
BiTree *CreateBiTree() {
    BiTree *T = NULL;
    char node = 0;

    while ((node = getchar()) == '\n')
        printf("尚未输入完成，请继续输入: ");

    if (node == '#')
        return NULL;
    else {
        T = (BiTree *)calloc(1, sizeof(BiTree));
        T->data = node;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }

    return T;
}

/**
 * @brief 前序遍历
 *
 * @param T 二叉链表根节点指针
 */
void PreOrder(BiTree *T) {
    if (T == NULL)
        return;

    putchar(T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

/**
 * @brief 中序遍历
 *
 * @param T 二叉链表根节点指针
 */
void InOrder(BiTree *T) {
    if (T == NULL)
        return;

    InOrder(T->lchild);
    putchar(T->data);
    InOrder(T->rchild);
}

/**
 * @brief 后续遍历
 * 
 * @param T 二叉链表根节点指针
 */
void PostOrder(BiTree *T) {
    if (T == NULL)
        return;

    PostOrder(T->lchild);
    PostOrder(T->rchild);
    putchar(T->data);
}

/**
 * @brief 计算叶子节点数
 *
 * @param T 二叉链表根节点指针
 * @param count 上一次递归的节点数
 * @return int 叶子节点数
 */
int Leaves(BiTree *T) {
    int count = 0;

    if (T == NULL)
        return 0;

    if (T->lchild == NULL && T->rchild == NULL)
        return 1;

    count += Leaves(T->lchild);
    count += Leaves(T->rchild);

    return count;
}

/**
 * @brief 计算叶子节点数
 *
 * @param T 二叉链表根节点指针
 * @return int 叶子节点数
 */
// #define Leaves(T) _Leaves(T, 0)

/**
 * @brief 计算二叉链表高度
 *
 * @param T 二叉链表根节点指针
 * @return int 二叉链表高度
 */
int Height(BiTree *T) {
    if (T == NULL)
        return 0;

    int leftHeight = Height(T->lchild) + 1,
        rightHeight = Height(T->rchild) + 1;

    return __max(leftHeight, rightHeight);
}

/**
 * @brief 主函数
 *
 * @return int 执行结果
 */
int main() {
    while (true) {
        system("cls");
        fflush(stdin);

        printf("请输入二叉树的前序遍历, 以 # 号为空: ");
        gT = CreateBiTree();

        printf("前序遍历: ");
        PreOrder(gT);
        putchar('\n');

        printf("中序遍历: ");
        InOrder(gT);
        putchar('\n');

        printf("后序遍历: ");
        PostOrder(gT);
        putchar('\n');

        printf("叶子节点数: %d\n", Leaves(gT));
        printf("树高度: %d\n", Height(gT));

        system("pause");
    }
}
