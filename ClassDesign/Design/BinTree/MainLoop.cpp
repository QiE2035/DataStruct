#include "MainLoop.hpp"

namespace MainLoop {

/**
 * @brief 主循环
 * 
 * @param Callback 回调
 */
void MainLoop(function<void()> Callback) {
    while (true) {
        system("cls");
        Callback();
        system("pause");
    }
}

} // namespace MainLoop