#include <stdio.h>

#include "log.h"

/**
 * @brief 日志函数
 * 
 * @param tag 日志标签 (级别)
 * @param fn_name 函数名
 * @param fmt 待格式化的字符串
 * @param ... 可变参数
 */
void log_log(char *tag, const char *fn_name, char *fmt, ...)
{
    va_list ap;
    fprintf(stderr, "[%s] %s(): ", tag, fn_name);
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fputc('\n', stderr);
}
