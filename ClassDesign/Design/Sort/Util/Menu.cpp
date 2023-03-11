#include "Menu.hpp"

using std::cin, std::cout, std::endl;

namespace Menu {

void Menu::Main() {
    int choose = 0;
    while (true) {
        system("cls");

        Print();

        cout << "请输入选项: ";
        cin >> choose;
        cout << endl;
        if (choose < 0 || choose > items.size())
            cout << "选项无效, 请重新选择!" << endl;
        else
            items[choose].run();

        cout << endl;
        system("pause");
    }
}

void Menu::Print() {
    cout << title << endl;

    PrintSplit();
    for (int i = 0; i < items.size(); i++)
        cout << i << ". " << items[i].name << endl;
    PrintSplit();
}

void Menu::PrintSplit() {
    for (int i = 0; i < maxLenth; i++)
        cout << '-';
    cout << endl;
}

} // namespace Menu
