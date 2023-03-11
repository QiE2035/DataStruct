#pragma once

#include <bits/stdc++.h>

using std::function;

namespace BinTree {

/**
 * @brief 无数据 throw
 * 
 */
class NoData {};

/**
 * @brief 遍历顺序
 * 
 */
enum class Order {
    /**
     * @brief 前序
     * 
     */
    PRE,
    /**
     * @brief 中序
     * 
     */
    IN,
    /**
     * @brief 后序
     * 
     */
    POST,
};

/**
 * @brief 二叉树
 * 
 * @tparam T 数据类型
 */
template <typename T>
struct Node {
    /**
     * @brief 数据
     *
     */
    T data;
    /**
     * @brief 左右孩子
     *
     */
    Node *leftChild = nullptr,
         *rightChild = nullptr;

    /**
     * @brief Construct a new Node object
     *
     */
    Node() {}

    /**
     * @brief Construct a new Node object
     *
     * @param NewData 数据回调
     */
    Node(function<T()> NewData) { CreateBinTree(this, NewData); }

#define _ForEach(param) \
    /**                 \
     * @brief 遍历    \
     *                  \
     */                 \
    void ForEach(Order order, function<void(param)> Callback)

    _ForEach(T) {
        ForEach(order, [&Callback](Node *node) { Callback(node->data); });
    }
    _ForEach(Node *);

#undef _ForEach

    /**
     * @brief 叶子节点数
     *
     * @return int 叶子节点数
     */

    int LeafCount();

    /**
     * @brief 树高度
     *
     * @return int 树高度
     */
    int Height();

  protected:
    Node *CreateBinTree(Node *tree, function<T()> NewData);
};

}; // namespace BinTree

#include "BinTree.ipp"
