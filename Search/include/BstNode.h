#ifndef _BST_NODE_
#define _BST_NODE_

typedef int DataType;

typedef struct node {
    DataType key;
    struct node *lchild, *rchild;
} BstNode;

#endif // _BST_NODE_
