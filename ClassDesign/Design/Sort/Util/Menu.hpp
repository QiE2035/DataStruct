#pragma once

#include <bits/stdc++.h>

using std::string, std::function, std::vector, std::max;

/**
 * @brief 菜单
 *
 */
namespace Menu {

/**
 * @brief 菜单项
 *
 */
struct Item {
    /**
     * @brief 名字
     *
     */
    string name;
    /**
     * @brief 回调
     *
     */
    function<void()> run;
    /**
     * @brief Construct a new Item object
     *
     * @param name 名字
     * @param run 回调
     */
    Item(string name, function<void()> run) : name(name), run(run) {}
};

/**
 * @brief 菜单
 * 
 */
class Menu {
    /**
     * @brief 菜单项
     *
     */
    vector<Item> items;
    /**
     * @brief 标题
     *
     */
    string title;
    /**
     * @brief 菜单项最大长度
     *
     */
    int maxLenth = 7;

    /**
     * @brief 输出菜单
     *
     */
    void Print();
    /**
     * @brief 输出分隔符
     *
     */
    void PrintSplit();

#define AddItem(name, run, str, plus)      \
    items.push_back(*new Item(name, run)); \
    maxLenth = max(maxLenth, (int)str.size() + plus)

  public:
    /**
     * @brief 菜单 构造函数
     *
     * @param title 菜单标题
     */
    Menu(string title) : title(title) {
        AddItem(
            "退出", [] { exit(0); }, title, 0);
    }

    /**
     * @brief 增加菜单项
     *
     * @param name 选项名
     * @param run 回调
     */
    void Add(string name, function<void()> run) {
        AddItem(name, run, name, 3);
    }

#undef AddItem

    /**
     * @brief 菜单主函数
     *
     */
    void Main();
};

} // namespace Menu
