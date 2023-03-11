#include <stdio.h>
#include <stdlib.h>

#include "main_loop.h"

/**
 * @brief 主循环函数
 * 
 * @param callback 回调
 */
void main_loop(main_loop_callback callback)
{
    bool is_continue = true;

    while (is_continue)
    {
        system("cls");

        callback();

        printf("按回车继续, 输入 0 退出: ");

        fflush(stdin);
        is_continue = getchar() - '0';
        fflush(stdin);
    }
}