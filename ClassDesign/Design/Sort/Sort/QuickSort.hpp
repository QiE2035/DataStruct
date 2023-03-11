#pragma once

#include <bits/stdc++.h>

using std::vector;

namespace Sort {

/**
 * @brief 快速排序 (内联)
 *
 * @tparam T 数据类型
 * @param R 待排序内容
 */
template <typename T>
inline void QuickSort(vector<T> &R);

} // namespace Sort

#include "QuickSort.ipp"
