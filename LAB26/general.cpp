#include <iostream>
#include "taskmanager.h"
using namespace std;
int main() {
    short user_choice;

    cout << "==============================================================" << endl;
    cout << "добро пожаловать в ГРАФФИТИ. ловко я с названием придумал, да?" << endl;
    cout << "==============================================================" << endl;
    cout << "1. Graf1\n2. Graf4\n3. Graf8\n4. Создать FileName" << endl;
    cin >> user_choice;
    
    while (user_choice < 1 || user_choice > 4) {
        cout << "выбери нормально пожалуйста. пж. пж. умоляю" << endl;
        cin >> user_choice;
    }

    switch (user_choice) {
        case 1:
            Graf1();
            break;
        case 2:
            Graf4();
            break;
        case 3:
            Graf8();
            break;
        case 4:
            CreateFileName();
            break;
    }

    return 0;
}