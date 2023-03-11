namespace Sort {

/**
 * @brief 堆排序调整
 *
 * @tparam T 数据类型
 * @param R 待排序内容
 * @param start 起始下标
 * @param end 结束下标
 */
template <typename T>
void HeapSift(vector<T> &R, int start, int end) {
    T rc = R[start];
    int big = 2 * start;
    while (big <= end) {
        if (big < end && R[big] < R[big + 1])
            big++;
        if (rc > R[big])
            break;
        R[start] = R[big];
        start = big;
        big *= 2;
    }
    R[start] = rc;
}

/**
 * @brief 堆排序
 *
 * @tparam T 数据类型
 * @param R 待排序内容
 * @param n 元素数量
 */
template <typename T>
void HeapSort(vector<T> &R, int n) {
    for (int i = n / 2; i >= 1; i--)
        HeapSift(R, i, n);
    for (int i = n; i > 1; i--) {
        T x = R[i];
        R[i] = R[1];
        R[1] = x;
        HeapSift(R, 1, i - 1);
    }
}

/**
 * @brief 堆排序 (内联)
 *
 * @tparam T 数据类型
 * @param R 待排序内容
 */
template <typename T>
inline void HeapSort(vector<T> &R) {
    auto tmp = R[0];
    HeapSort(R, R.size() - 1);
    R[0] = tmp;
}

} // namespace Sort