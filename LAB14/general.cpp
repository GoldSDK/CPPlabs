#include <iostream>
#include "taskmanager.h"
int main() {
    int user_choice;

    std::cout << "Пламенно приветствуем в БИНАРЩИКЕ. Что тебе сегодня надо?\n1. File8\n2. File41\n3. File50\n4. Recur15" << std::endl;
    std::cin >> user_choice;
    while (user_choice < 1 || user_choice > 4) {
        std::cout << "Еще один такой. Какой кошмар. Советую посетить окулиста или офтальмолога." << std::endl;
        std::cin >> user_choice;
    }
    switch (user_choice) {
        case 1:
            File8();
            break;
        case 2:
            File41();
            break;
        case 3:
            File50();
            break;
        case 4:
            Recur15();
            break;
    }
}