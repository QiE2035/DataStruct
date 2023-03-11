#pragma once

#include <bits/stdc++.h>

using std::function;

namespace MainLoop {

/**
 * @brief 主循环
 *
 * @param Callback 回调
 */
void MainLoop(function<void()> Callback);

} // namespace MainLoop
