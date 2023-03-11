namespace VectorUtil {

/**
 * @brief  输出向量
 *
 * @tparam T   元素类型
 * @param  tip 输出提示
 * @param  R   目标向量
 */
template <typename T>
void Print(vector<T> &R) {
    for (auto &&data : R)
        if (data)
            cout << data << ' ';
}

} // namespace VectorUtil