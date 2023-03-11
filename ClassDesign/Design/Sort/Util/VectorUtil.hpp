#pragma once

#include <bits/stdc++.h>

using std::string, std::vector;

using std::cin, std::cout, std::endl;

/**
 * @brief 向量工具
 * 
 */
namespace VectorUtil {

/**
 * @brief  输出向量
 *
 * @tparam T   元素类型
 * @param  R   目标向量
 */
template <typename T>
void Print(vector<T> &R);

/**
 * @brief 输入向量
 * 
 * @return vector<int>& 输入结果 
 */
vector<int> &InputIntVector();

/**
 * @brief 生成随机整数向量
 * 
 * @param size 要生成的数量
 * @return vector<int>& 生成结果
 */
vector<int> &GenRandIntVec(int size);

} // namespace VectorUtil

#include "VectorUtil.ipp"