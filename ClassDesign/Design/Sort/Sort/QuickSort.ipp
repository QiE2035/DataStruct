namespace Sort {

/**
 * @brief 快速排序分割
 *
 * @tparam T    数据类型
 * @param  R    待排序内容
 * @param  low  低下标
 * @param  high 高下标
 * @return int  分割下标
 */
template <typename T>
int partition(vector<T> &R, int low, int high) {
    int threshold = R[0] = R[low]; // 临界值
    while (low < high) {
        while ((low < high) && (R[high] >= threshold)) high--;
        if (low < high)
            R[low] = R[high];
        while ((low < high) && (R[low] <= threshold)) low++;
        if (low < high)
            R[high] = R[low];
    }
    R[low] = R[0];
    return low;
}

/**
 * @brief 快速排序递归
 *
 * @tparam T 数据类型
 * @param R 待排序内容
 * @param low 低下标
 * @param high 高下标
 */
template <typename T>
void QuickSort(vector<T> &R, int low, int high) {
    if (low < high) {
        int part = partition(R, low, high);
        QuickSort(R, low, part - 1);
        QuickSort(R, part + 1, high);
    }
}

/**
 * @brief 快速排序 (内联)
 *
 * @tparam T 数据类型
 * @param R 待排序内容
 */
template <typename T>
inline void QuickSort(vector<T> &R) {
    auto tmp = R[0];
    QuickSort(R, 1, R.size() - 1);
    R[0] = tmp;
}

} // namespace Sort
