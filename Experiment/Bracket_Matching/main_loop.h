#ifndef _MAIN_LOOP_
#define _MAIN_LOOP_

#include <stdbool.h>

/**
 * @brief 主循环回调
 * 
 */
typedef void (*main_loop_callback)();

/**
 * @brief 主循环回调宏定义
 * 
 */
#define MAIN_LOOP_CALLBACK(function_name) void function_name()


/**
 * @brief 主循环函数
 * 
 * @param callback 回调
 */
void main_loop(main_loop_callback callback);

#endif // _MAIN_LOOP_
