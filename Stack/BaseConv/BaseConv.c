#include <stdio.h>
#include <stdlib.h>

#include "LinkStack.h"

/**
 * @brief 进制转换
 *
 * @param in 输入数据
 * @param base 目标进制
 * @return LinkStack* 转换结果
 */
LinkStack *conv(long in, short base) {
    DataType bit = 0;
    LinkStack *s = initStack();

    do {
        bit = in % base;
        if (bit < 0) {
            bit -= base; // 转为正数
            in += base;
        }
        if (bit >= 10)
            bit += 'A' - 10; // 大于9的用字母
        else
            bit += '0';   // 转换成对应字符
        s = push(s, bit); // 将结果入栈

    } while (in /= base);

    return s;
}

/**
 * @brief 输出结果
 *
 * @param s 目标链栈
 */
void print_result(LinkStack *s) {
    while (s) {
        printf("%c", top(s));
        s = pop(s);
    }
}

/**
 * @brief 输出提示
 *
 */
void print_hint() {
    puts("\n\n\n\t 进制转换器");
    puts("\t 最大 36 进制");
    puts("\t 可为负进制");
    puts("\t 输入 0 退出");
    puts("\t ----------\n\n\n");
}

/**
 * @brief 输入数据
 *
 * @param in 数据指针
 * @param base 进制指针
 */
void input(long *in, short *base) {
    // 输入数字
    printf("    请输入要转换的数字: ");
    scanf("%ld", in);
    getchar(); // 清除回车

    // 输入 0 则退出
    if (*in == 0) {
        return;
    }

    // 输入进制
    printf("    请输入要转换的进制: ");
    scanf("%hd", base);
    getchar(); // 清除回车
}

/**
 * @brief 主函数
 *
 * @return int 执行结果
 */
int main() {
    // 变量
    long in = 0;
    short base = 0;

    system("chcp 65001"); // 使用 UTF-8 编码

    // 主循环
    while (true) {
        print_hint();      // 打印提示
        input(&in, &base); // 输入数据

        // 判断退出
        if (in == 0)
            break;

        // 进制是否合法
        if (abs(base) <= 1 || abs(base) > 36)
            printf("    进制不能为 %d\n", base);
        else {
            // 转换并输出
            printf("    转换的结果为: ");
            print_result(conv(in, base));
        }

        // 暂停
        printf("\n    ");
        system("pause");
        system("cls"); // 清屏
    }

    return 0;
}
