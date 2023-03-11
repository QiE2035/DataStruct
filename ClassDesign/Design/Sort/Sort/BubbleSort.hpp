#pragma once

#include <bits/stdc++.h>

using std::vector;

namespace Sort {

/**
 * @brief 冒泡排序
 * 
 * @tparam T 数据类型
 * @param R 数据序列
 */
template<typename T>
void BubbleSort(vector<T> &R);

} // namespace Sort

#include "BubbleSort.ipp"