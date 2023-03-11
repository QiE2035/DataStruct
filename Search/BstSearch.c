#include <stdio.h>
#include <stdlib.h>

#include "BstNode.h"

BstNode *searchBst(BstNode *node, DataType key) {
    while (node != NULL) {
        if (node->key == key)
            return node;
        if (node->key > key)
            node = node->lchild;
        else
            node = node->rchild;
    }
    return NULL;
}

BstNode *insertNode(BstNode *root, BstNode *newNode) {
    BstNode *currentNode, *parentNode;
    if (root == NULL)
        return newNode;
    while (currentNode != NULL) {
        parentNode = currentNode;
        if (newNode->key == currentNode->key)
            return root;
        if (newNode->key < currentNode->key)
            currentNode = currentNode->lchild;
        else
            currentNode = currentNode->rchild;
    }
    if (newNode->key < parentNode->key)
        parentNode->lchild = newNode;
    else
        parentNode->rchild = newNode;
    return root;
}

BstNode *createBst() {
    BstNode *root = NULL, *newNode;
    DataType key;
    scanf("%d", &key);
    while (key != 1) {
        newNode = (BstNode *)calloc(1, sizeof(BstNode));
        newNode->key = key;
        root = insertNode(root, newNode);
        scanf("%d", &key);
    }
    return root;
}

BstNode *deleteNode(BstNode *t, DataType k) {
    BstNode *p = t, *q, *s = NULL;
    while (p != NULL) {
        if (p->key == k)
            break;
        s = p;
        if (p->key > k)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == t)
            t = NULL;
        else if (s->lchild == p)
            s->lchild = NULL;
        else
            s->rchild = NULL;
    }else if (p->lchild==NULL)
    {
        // TODO: to be finish
    }
    
}