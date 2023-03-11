#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"
#include "menu.h"

/**
 * @brief 获取菜单项描述最大长度
 *
 * @param menu 菜单结构体指针
 * @return int 长度
 */
int max_item_len(menu_t *menu)
{
    int len = 0, tmp = 0;

    for (char i = 1; i <= menu->size; i++)
        if ((tmp = strlen(menu->items[i - 1].desc)) > len)
            len = tmp;

    return len + 3;
}

/**
 * @brief 输出分割符
 *
 * @param len 长度
 */
void print_split(int len)
{
    for (int i = 0; i < len; i++)
        putchar('-');
    putchar('\n');
}

/**
 * @brief 输出菜单项
 *
 * @param menu 菜单项指针
 */
void print_menu(menu_t *menu)
{
    int len = max_item_len(menu);

    puts(menu->title);

    print_split(len);

    for (char i = 1; i <= menu->size; i++)
        printf("%d. %s\n", i, menu->items[i - 1].desc);
    puts("0. 退出");

    print_split(len);

    printf("请输入选项: ");
}

/**
 * @brief 初始化菜单结构体
 *
 * @param menu 菜单结构体指针
 * @param title 菜单标题
 * @param size 菜单大小
 */
void init_menu(menu_t *menu, char *title, int size)
{
    menu->title = title;
    menu->size = size;
    menu->items = (menu_item *)malloc(sizeof(menu_item) * size);
}

/**
 * @brief 菜单主函数
 *
 * @param menu
 */
void menu_main(menu_t *menu)
{
    short choose = 0;
    do
    {
        print_menu(menu);
        scanf("%hd", &choose);
        getchar();
        putchar('\n');

        if (choose > 0 && choose <= menu->size)
        {
            menu->items[choose - 1].fun();
            putchar('\n');
        }

        system("pause");
        system("cls");
    } while (choose);
}

/**
 * @brief 添加菜单项
 *
 * @param menu 菜单指针
 * @param desc 菜单描述
 * @param fun 菜单函数
 */
void add_menu(menu_t *menu, char *desc, menu_fun fun)
{
    static char i = 0;
    if (i >= menu->size)
    {
        log_err("菜单列表溢出!");
        return;
    }

    menu->items[i++] = (menu_item){
        .desc = desc,
        .fun = fun,
    };
}