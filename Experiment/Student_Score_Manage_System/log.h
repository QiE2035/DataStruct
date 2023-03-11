#ifndef _LOG_
#define _LOG_

#include <stdarg.h>

/**
 * @brief 日志函数
 *
 * @param tag 日志标签 (级别)
 * @param fn_name 函数名
 * @param fmt 待格式化的字符串
 * @param ... 可变参数
 */
void log_log(char *tag, const char *fn_name, char *fmt, ...);

/**
 * @brief 指定 tag 日志
 *
 * @param tag 日志标签 (级别)
 * @param ... 可变参数
 */
#define log_tag(tag, ...) log_log(tag, __FUNCTION__, __VA_ARGS__)

/**
 * @brief 错误日志
 *
 * @param ... 可变参数
 */
#define log_err(...) log_tag("ERROR", __VA_ARGS__)

/**
 * @brief 警告日志
 *
 * @param ... 可变参数
 */
#define log_warn(...) log_tag("WARN", __VA_ARGS__)

/**
 * @brief 信息日志
 *
 * @param ... 可变参数
 */
#define log_info(...) log_tag("INFO", __VA_ARGS__)

/**
 * @brief 调试日志
 *
 * @param ... 可变参数
 */
#define log_dbg(...) log_tag("DEBUG", __VA_ARGS__)

#endif // _LOG_
