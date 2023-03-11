#pragma once

#include <bits/stdc++.h>

using std::function, std::vector;

/**
 * @brief With 工具
 * 
 */
namespace WithUtil {

/**
 * @brief 计时运行
 * 
 * @param run 回调
 * @return int 用时 微秒
 */
int WithTimer(function<void()> run);

/**
 * @brief 以生成随机整数向量运行
 * 
 * @param run 回调
 */
void WithRandIntVec(function<void(vector<int> &)> run);

} // namespace WrapperUtil
