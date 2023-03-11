#include "VectorUtil.hpp"

namespace VectorUtil {

vector<int> &InputIntVector() {
    auto R = new vector<int>(1, 0);
    int data;

    cout << "请输入数字, 以空格分隔, 以 0 结束: ";
    do {
        cin >> data;
        R->push_back(data);
    } while (data);

    return *R;
}

vector<int> &GenRandIntVec(int size) {
    auto R = new vector<int>(1, 0);

    srand(time(nullptr));

    for (int i = 0; i < size; i++)
        R->push_back(rand() % 1000 + 1);

    return *R;
}

} // namespace VectorUtil
