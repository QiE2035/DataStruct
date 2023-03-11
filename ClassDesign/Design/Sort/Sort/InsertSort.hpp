#pragma once

#include <bits/stdc++.h>

using std::vector;

namespace Sort {

/**
 * @brief 插入排序
 *
 * @tparam T 数据类型
 * @param R 数据序列
 */
template <typename T>
void InsertSort(vector<T> &R);

} // namespace Sort

#include "InsertSort.ipp"