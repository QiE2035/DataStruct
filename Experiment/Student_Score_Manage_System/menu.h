#ifndef _MENU_
#define _MENU_
/**
 * @brief 菜单回调
 *
 */
typedef void (*menu_fun)();

/**
 * @brief 菜单项
 *
 */
typedef struct menu_item
{
    // 描述
    char *desc;
    // 函数
    menu_fun fun;
} menu_item;

/**
 * @brief 菜单结构体
 *
 */
typedef struct menu_t
{
    // 标题
    char *title;
    // 大小
    char size;
    // 菜单项
    menu_item *items;
} menu_t;

/**
 * @brief 菜单主函数
 *
 * @param menu
 */
void menu_main(menu_t *menu);

/**
 * @brief 初始化菜单结构体
 *
 * @param menu 菜单结构体指针
 * @param title 菜单标题
 * @param size 菜单大小
 */
void init_menu(menu_t *menu, char *title, int size);

/**
 * @brief 新建菜单项
 *
 * @param menu 菜单指针
 * @param desc 描述
 * @param fun 函数指针
 * @return menu_item 菜单项
 */
void add_menu(menu_t *menu, char *desc, menu_fun fun);

/**
 * @brief 输出分割符
 *
 * @param len 长度
 */
void print_split(int len);

#endif // _MENU_
