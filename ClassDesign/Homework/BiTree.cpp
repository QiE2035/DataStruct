/**
 * @file BiTree.cpp
 * @author 杜思维 (计算机212-15)
 * @brief 二叉链表 (非递归法)
 * @version 0.1
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

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
 * @brief 二叉链表指针，全局方便调试
 *
 */
BiTree *gT;

/**
 * @brief 获取节点字符
 *
 */
#define getNodeChar()                      \
    while ((nodeChar = getchar()) == '\n') \
    cout << "尚未输入完成，请继续输入: "

/**
 * @brief 新节点
 *
 * @param child 要设置的孩子节点
 */
#define newNode(child)                       \
    T = (BiTree *)calloc(1, sizeof(BiTree)); \
    T->data = nodeChar;                      \
    biTreeStack.top()->child = T;            \
    biTreeStack.push(T)

/**
 * @brief 创建二叉链表
 *
 * @return BiTree* 二叉链表根节点指针
 */
BiTree *CreateBiTree() {
    BiTree *T = nullptr, *root = nullptr;
    char nodeChar = 0;
    stack<BiTree *> biTreeStack;

    cout << "请输入二叉树的前序遍历, 以 # 号为空: ";

    getNodeChar();
    if (nodeChar == '#')
        return nullptr;

    root = T = (BiTree *)calloc(1, sizeof(BiTree));
    T->data = nodeChar;
    biTreeStack.push(T);

    while (!biTreeStack.empty()) {
        while (biTreeStack.top()->lchild == nullptr) {
            getNodeChar();
            if (nodeChar == '#')
                break;
            else {
                newNode(lchild);
            }
        }

        getNodeChar();
        if (nodeChar == '#')
            biTreeStack.pop();
        else {
            newNode(rchild);
        }

        while (!biTreeStack.empty() && biTreeStack.top()->rchild != nullptr) {
            T = biTreeStack.top();
            biTreeStack.pop();
        }

        if (biTreeStack.empty())
            break;
    }
    return root;
}

/**
 * @brief 中序遍历
 *
 * @param T 二叉链表根节点指针
 */
void InOrder(BiTree *T) {
    stack<BiTree *> biTreeStack;
    cout << "中序遍历: ";
    while (true) {
        while (T != nullptr) {
            biTreeStack.push(T);
            T = T->lchild;
        }
        if (biTreeStack.empty())
            break;
        T = biTreeStack.top();
        biTreeStack.pop();
        cout << T->data;
        T = T->rchild;
    }
    cout << endl;
}

/**
 * @brief 前序遍历
 *
 * @param T 二叉链表根节点指针
 */
void PreOrder(BiTree *T) {
    stack<BiTree *> biTreeStack;
    cout << "前序遍历: ";
    while (true) {
        while (T != nullptr) {
            cout << T->data;
            biTreeStack.push(T);
            T = T->lchild;
        }
        if (biTreeStack.empty())
            break;
        T = biTreeStack.top();
        biTreeStack.pop();
        T = T->rchild;
    }
    cout << endl;
}

/**
 * @brief 后序遍历
 *
 * @param T 二叉链表根节点指针
 */
void PostOrder(BiTree *T) {
    stack<BiTree *> biTreeStack;
    cout << "后序遍历: ";

    biTreeStack.push(T);
    biTreeStack.push(T);
    while (!biTreeStack.empty()) {
        T = biTreeStack.top();
        biTreeStack.pop();
        if (!biTreeStack.empty() && T == biTreeStack.top()) {
            if (T->rchild != nullptr) {
                biTreeStack.push(T->rchild);
                biTreeStack.push(T->rchild);
            }
            if (T->lchild != nullptr) {
                biTreeStack.push(T->lchild);
                biTreeStack.push(T->lchild);
            }
        } else
            cout << T->data;
    }
    cout << endl;
}

/**
 * @brief 计算叶子节点数
 *
 * @param T 二叉链表根节点指针
 * @return int 叶子节点数
 */
int Leaves(BiTree *T) {
    stack<BiTree *> biTreeStack;
    int count = 0;
    while (true) {
        while (T != nullptr) {
            if (T->lchild == nullptr && T->rchild == nullptr)
                count++;
            biTreeStack.push(T);
            T = T->lchild;
        }
        if (biTreeStack.empty())
            break;
        T = biTreeStack.top();
        biTreeStack.pop();
        T = T->rchild;
    }
    return count;
}

/**
 * @brief 层序遍历计算二叉链表高度
 *
 * @param T 二叉链表根节点指针
 * @return int 二叉链表高度
 */
int Height(BiTree *T) {
    queue<BiTree *> biTreeQueue;
    int height = 0;
    BiTree *last = T;

    if (T == nullptr)
        return 0;

    biTreeQueue.push(T);
    while (!biTreeQueue.empty()) {
        T = biTreeQueue.front();
        biTreeQueue.pop();
        if (T->lchild != nullptr)
            biTreeQueue.push(T->lchild);
        if (T->rchild != nullptr)
            biTreeQueue.push(T->rchild);
        if (T == last) {
            height++;
            last = biTreeQueue.back();
        }
    }

    return height;
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

        gT = CreateBiTree();
        PreOrder(gT);
        InOrder(gT);
        PostOrder(gT);
        cout << "叶子节点数: " << Leaves(gT) << endl
             << "树高度: " << Height(gT) << endl;

        system("pause");
    }
}
