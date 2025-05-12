#include <iostream>
#include "taskmanager.h"
int main() {
    int user_choice;

    std::cout << "Пламенно приветствуем в КАЛЬКДЕРЕВЕ. Что тебе опять сегодня надо?\n1. CalcTree5\n2. CalcTree23" << std::endl;
    std::cin >> user_choice;
    while (user_choice < 1 || user_choice > 2) {
        std::cout << "Еще один такой. Какой кошмар. Советую посетить окулиста или офтальмолога." << std::endl;
        std::cin >> user_choice;
    }
    switch (user_choice) {
        case 1:
            CalcTree5();
            break;
        case 2:
            CalcTree23();
            break;
    }
}
