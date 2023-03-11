#include "WithUtil.hpp"
#include "VectorUtil.hpp"

using std::chrono::steady_clock,
    std::chrono::duration_cast,
    std::chrono::microseconds,
    std::cin, std::cout;

namespace WithUtil {

int WithTimer(function<void()> run) {
    auto start = steady_clock::now();
    run();
    return duration_cast<microseconds>(steady_clock::now() - start).count();
}

void WithRandIntVec(function<void(vector<int> &)> run) {
    int size = 0;
    cout << "请输入元素数量: ";
    cin >> size;
    cout << endl;
    run(VectorUtil::GenRandIntVec(size));
}

} // namespace WithUtil