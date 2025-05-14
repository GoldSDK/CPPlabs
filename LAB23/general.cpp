#include <iostream>
#include "taskmanager.h"
int main() {
    int user_choice;

    std::cout << "Пламенно приветствуем в ВЕСЕЛОМ ДЕРЕВЕ. Что тебе опять сегодня надо?\n1. TreeFun1\n2. TreeFun3\n3. TreeFun13" << std::endl;
    std::cin >> user_choice;
    while (user_choice < 1 || user_choice > 3) {
        std::cout << "Еще один такой. Какой кошмар. Советую посетить окулиста или офтальмолога." << std::endl;
        std::cin >> user_choice;
    }
    switch (user_choice) {
        case 1:
            TreeFun1();
            break;
        case 2:
            TreeFun3();
            break;
	    case 3:
            TreeFun13();
	        break;
    }
}
