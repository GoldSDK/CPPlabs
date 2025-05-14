#include <iostream>
#include "taskmanager.h"
int main() {
    int user_choice;

    std::cout << "Пламенно приветствуем в БИНАРЩИКЕ. Что тебе опять сегодня надо?\n1. создать файл\n2. File8\n3. File41\n4. File50\n5. Recur15" << std::endl;
    std::cin >> user_choice;
    while (user_choice < 1 || user_choice > 5) {
        std::cout << "Еще один такой. Какой кошмар. Советую посетить окулиста или офтальмолога." << std::endl;
        std::cin >> user_choice;
    }
    switch (user_choice) {
        case 1:
            Create();
            break;
        case 2:
            File8();
            break;
        case 3:
            File41();
            break;
        case 4:
            File50();
            break;
        case 5:
            Recur15();
            break;
    }
}