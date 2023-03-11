#include "BinTree.hpp"
#include "MainLoop.hpp"

using namespace BinTree;
using std::cin, std::cout, std::endl;

/**
 * @brief 主函数
 *
 * @return int 运行结果
 */
int main() {
    MainLoop::MainLoop([] {
        cout << "请输入二叉树的前序序列, 以 # 为空: ";

        Node<char> tree([] {
            char tmp = 0;
            cin >> tmp;
            if (tmp == '#')
                throw NoData();
            return tmp;
        });

#define _ForEach(_char, order)                                          \
    cout << _char                                                       \
         << "序遍历: ";                                                 \
    tree.ForEach(Order::order, [](char data) { cout << data << ' '; }); \
    cout << endl

        _ForEach("前", PRE);
        _ForEach("中", IN);
        _ForEach("后", POST);

#undef _ForEach

        cout << "叶子节点数: " << tree.LeafCount() << endl
             << "树高度: " << tree.Height() << endl;
    });

    return 0;
}
