#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"
#include "menu.h"
#include "LinkList.h"

#define CSV_NAME "export.csv"

LinkList *pList = NULL;

/**
 * @brief 读入数据 (回调)
 *
 * @return DataType 读入的数据
 */
DataType input_data(jmp_buf *jb)
{
    DataType x;

    printf("请输入学号: ");
    scanf("%d", &x.sno);

    printf("请输入姓名: ");
    scanf("%s", &x.name);

    printf("请输入成绩: ");
    scanf("%d", &x.score);

    getchar();

    return x;
}

/**
 * @brief 输出 JSON 回调
 *
 * @param x 遍历项
 */
void print_json(LinkList *pNode)
{
    puts("    {");
    printf("        \"sno\": %d,\n", pNode->data.sno);
    printf("        \"name\": \"%s\",\n", pNode->data.name);
    printf("        \"score\": %d\n", pNode->data.score);
    printf("    }");
}

/**
 * @brief 菜单回调 创建
 *
 */
void menu_create()
{
    pList = createTailList(input_data, true);
}

/**
 * @brief 链表判空 (初始化)
 *
 * @retval true 不为空 (已初始化)
 * @retval false 为空 (未初始化)
 */
bool check_not_null()
{
    if (pList && pList->next)
        return true;
    log_err("数据为空, 请先创建!");
    return false;
}

/**
 * @brief 菜单回调 输出 JSON
 *
 */
void menu_json()
{
    if (check_not_null())
        printList(pList, print_json, true);
}

/**
 * @brief 遍历回调 输出表格
 *
 * @param pNode 节点指针
 */
void print_table(LinkList *pNode)
{
    printf("%-10d | %-6s | %d\n",
           pNode->data.sno,
           pNode->data.name,
           pNode->data.score);
}

/**
 * @brief 菜单回调 输出
 *
 */
void menu_print()
{
    if (check_not_null())
    {
        printf("%-10s | %-6s | %s\n", "学号", "姓名", "成绩");
        print_split(26);
        forEach(pList, print_table, false);
    }
}

/**
 * @brief 读入索引并查找节点
 *
 * @return LinkList* 找到的节点
 */
LinkList *input_get_node()
{
    printf("请输入节点索引: ");
    int i = 0;
    scanf("%d", &i);
    getchar();
    return getNode(pList, i - 1);
}

/**
 * @brief 菜单回调 删除
 *
 */
void menu_delete()
{
    if (check_not_null())
        deleteAfterNode(input_get_node());
}

/**
 * @brief 菜单回调 插入
 *
 */
void menu_insert()
{
    if (check_not_null())
        insertAfterNode(input_get_node(), input_data(NULL));
}

/**
 * @brief 要查找的成绩
 *
 */
int score = 0;

/**
 * @brief 按成绩查找节点回调
 *
 * @param n 遍历节点
 * @retval true 目标匹配
 * @retval false 目标不匹配
 */
bool find_by_score(LinkList *pNode)
{
    if (pNode->next)
        return pNode->next->data.score == score;
    return false;
}

/**
 * @brief 菜单回调 删除指定成绩
 *
 */
void menu_delete_score()
{
    if (check_not_null())
    {
        printf("请输入要查找的成绩: ");
        scanf("%d", &score);
        deleteAfterNode(findNode(pList, find_by_score, true));
    }
}

/**
 * @brief 文件名
 *
 */
#define FILE_NAME "data.dat"

/**
 * @brief 文件指针
 *
 */
FILE *pFile;

/**
 * @brief 遍历回调 保存文件
 *
 * @param pNode 节点指针
 */
void save_file(LinkList *pNode)
{
    fwrite(&pNode->data, sizeof(DataType), 1, pFile);
}

/**
 * @brief 遍历回调 加载文件
 *
 * @param jb 跨函数跳转的缓冲区
 * @return DataType 读取的节点数据
 */
DataType load_file(jmp_buf *jb)
{
    DataType x;
    if (!fread(&x, sizeof(DataType), 1, pFile))
    {
        longjmp(*jb, true);
    }
    else
        return x;
}

/**
 * @brief 菜单回调 保存文件
 *
 */
void menu_save()
{
    if (check_not_null())
    {

        if (!(pFile = fopen(FILE_NAME, "wb")))
            log_err("无法打开文件 \"%s\"! 文件被占用?", FILE_NAME);

        forEach(pList, save_file, false);

        fclose(pFile);

        log_info("操作完成!");
    }
}

/**
 * @brief 菜单回调 加载文件
 *
 */
void menu_load()
{
    if (!(pFile = fopen(FILE_NAME, "rb")))
        log_err("无法打开文件 \"%s\"! 文件不存在?", FILE_NAME);

    pList = createTailList(load_file, false);

    fclose(pFile);

    log_info("操作完成!");
}

/**
 * @brief 遍历回调 保存 CSV
 *
 * @param pNode 节点指针
 */
void save_csv(LinkList *pNode)
{
    fprintf(pFile, "%d,%s,%d\n",
            pNode->data.sno,
            pNode->data.name,
            pNode->data.score);
}

/**
 * @brief 菜单回调 保存 CSV
 *
 */
void menu_csv()
{
    if (check_not_null())
    {
        if (!(pFile = fopen(CSV_NAME, "w")))
            log_err("无法打开文件 \"%s\"! 文件被占用?", CSV_NAME);

        fputs("学号,姓名,成绩\n", pFile);
        forEach(pList, save_csv, false);

        fclose(pFile);

        log_info("操作完成!");
    }
}

/**
 * @brief 主函数
 *
 * @return int
 */
int main()
{
    menu_t menu, *pMenu = &menu;
    init_menu(pMenu, "学生成绩管理系统", 9);

    add_menu(pMenu, "创建数据", menu_create);
    add_menu(pMenu, "输出 JSON", menu_json);
    add_menu(pMenu, "插入节点", menu_insert);
    add_menu(pMenu, "删除节点", menu_delete);
    add_menu(pMenu, "删除指定成绩的节点", menu_delete_score);
    add_menu(pMenu, "保存到文件", menu_save);
    add_menu(pMenu, "从文件加载", menu_load);
    add_menu(pMenu, "保存到 CSV", menu_csv);
    add_menu(pMenu, "遍历输出", menu_print);

    menu_main(pMenu);

    return 0;
}
