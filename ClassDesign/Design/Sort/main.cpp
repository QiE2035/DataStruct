#include "Sort/Sort.hpp"
#include "Util/Util.hpp"

using namespace Sort;
using namespace WithUtil;

int main() {
    Menu::Menu menu("排序");

    auto sortFun = [](function<void(vector<int> &)> run) {
        WithRandIntVec([&run](vector<int> &R) {
            cout << "生成的序列: ";
            VectorUtil::Print(R);
            cout << endl
                 << endl
                 << "用时: "
                 << WithTimer([&R, &run] { run(R); })
                 << " 微秒"
                 << endl
                 << endl
                 << "排序结果: ";
            VectorUtil::Print(R);
            cout << endl;
        });
    };

#define AddMenu(name, run)                       \
    menu.Add(name, [&sortFun] {                  \
        sortFun([](vector<int> &R) { run(R); }); \
    })

    AddMenu("冒泡排序", BubbleSort);
    AddMenu("插入排序", InsertSort);
    AddMenu("选择排序", SelectSort);
    AddMenu("堆 排 序", HeapSort);
    AddMenu("快速排序", QuickSort);

#undef AddMenu

    menu.Main();
    return 0;
}
