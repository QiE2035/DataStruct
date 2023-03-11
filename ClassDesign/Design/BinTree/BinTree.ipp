using std::max;

namespace BinTree {

template <typename T>
int Node<T>::LeafCount() {
    int count = 0;

    ForEach(Order::PRE, [&count](Node *node) {
        if (node->leftChild == nullptr && node->rightChild == nullptr)
            count++;
    });

    return count;
}

#define _Height(child) \
    child == nullptr ? 1 : child->Height() + 1

template <typename T>
int Node<T>::Height() {

    int leftHeight = _Height(leftChild),
        rightHeight = _Height(rightChild);

    return max(leftHeight, rightHeight);
}

#undef _Height

#define NewChild(child) \
    node->child = CreateBinTree(new Node, NewData);

template <typename T>
Node<T> *Node<T>::CreateBinTree(Node *node, function<T()> NewData) {

    try {
        node->data = NewData();
        NewChild(leftChild);
        NewChild(rightChild);
    } catch (NoData &e) {
        delete node;
        node = nullptr;
    }

    return node;
}

#undef NewChild

#define ToChild(child)                   \
    if (child != nullptr) {              \
        child->ForEach(order, Callback); \
    }

#define _Callback(_order)         \
    if (order == Order::_order) { \
        Callback(this);           \
    }

template <typename T>
void Node<T>::ForEach(Order order, function<void(Node *)> Callback) {
    _Callback(PRE);
    ToChild(leftChild);
    _Callback(IN);
    ToChild(rightChild);
    _Callback(POST);
}

#undef ToChild
#undef _Callback

} // namespace BinTree