#include <stdio.h>
#include <stdlib.h>

#include "LinkStack.h"
#include "main_loop.h"

/**
 * @brief 链栈指针
 * 
 */
LinkStack *pStack;

/**
 * @brief 字符串长度
 * 
 */
#define STR_SIZE 100

/**
 * @brief 输出分割符
 * 
 * @param count 
 */
void print_split(char count)
{
    for (char i = 0; i < count; i++)
        putchar('-');
    putchar('\n');
}

/**
 * @brief 输出错误提示
 * 
 * @param index 索引
 * @param bracket 括号
 */

void print_error(index_t index, char bracket)
{
    if (index || !pStack)
    {
        printf("第 %d 个字符的括号 %c ", index + 1, bracket);
        if (pStack)
            printf("和");
    }
    if (pStack)
        printf("第 %d 个字符的括号 %c ",
               top(pStack).index + 1,
               top(pStack).bracket);
    puts("不匹配!");
}

/**
 * @brief 括号判定宏定义
 * 
 * @param left 左括号
 * @param right 右括号
 */
#define BRACKET_CASE(left, right)                         \
    case right:                                           \
        if (empty(pStack) || top(pStack).bracket != left) \
        {                                                 \
            print_error(i, str[i]);                       \
            return;                                       \
        }                                                 \
        pStack = pop(pStack);                             \
        break;

/**
 * @brief 输入数据
 * 
 * @param str 字符串指针
 */
void input_data(char *str)
{
    FILE *file = fopen("expr.txt", "r");

    bool is_read_file = true;
    if (file)
    {
        printf("检测到 expr.txt 文件, 按回车读入, 输入 0 跳过: ");
        fflush(stdin);
        is_read_file = getchar() - '0';
        fflush(stdin);
    }
    else
        is_read_file = false;

    if (is_read_file)
    {
        fgets(str, STR_SIZE, file);
        printf("读入的表达式为: %s\n", str);
    }
    else
    {
        printf("请输入表达式, 不支持中文, 至多 %d 个字符:\n", STR_SIZE);
        fflush(stdin);
        gets(str);
    }
}

/**
 * @brief 主循环回调
 * 
 */
MAIN_LOOP_CALLBACK(loop_callback)
{
    puts("\t\t括号匹配\n");
    puts("程序会自动检测运行目录中的 expr.txt 文件");
    print_split(40);

    char str[STR_SIZE] = "";
    input_data(str);

    pStack = initStack();

    for (index_t i = 0; str[i] != '\n' && str[i] != 0; i++)
    {
        if (str[i] == '(' || str[i] == '[' | str[i] == '{')
            pStack = push(pStack, INIT_DATA(str[i], i));
        else
            switch (str[i])
            {
                BRACKET_CASE('(', ')')
                BRACKET_CASE('[', ']')
                BRACKET_CASE('{', '}')
            }
    }

    if (empty(pStack))
        puts("括号匹配!");
    else
        print_error(0, 0);
}
/**
 * @brief 主函数
 * 
 * @return int 执行结果
 */
int main()
{
    main_loop(loop_callback);

    return 0;
}
