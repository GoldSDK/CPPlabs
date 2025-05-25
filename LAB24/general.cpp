#include <iostream>
#include <string>
#include <limits>
#include "taskmanager.h"
using namespace std;

int main() {
    short user_choice;

    cout << "меня зовут юлий цезарь. тебе надо зашифровать или расшифровать?" << endl;
    cout << "1. зашифровать\n2. расшифровать" << endl;
    cin >> user_choice;
    while (user_choice < 1 || user_choice > 2) {
        cout << "я так еще не умею. введи что тебе надо. нормально." << endl;
        cin >> user_choice;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string user_string;
    short shift;
    cout << "введи последовательность символов." << endl;
    getline(cin, user_string);

    cout << "введи сдвиг" << endl;
    cin >> shift;

    switch (user_choice) {
        case 1:
            cout << Cipher(user_string, shift) << endl;
            break;
        case 2:
            cout << Decipher(user_string, shift) << endl;
            break;
    }

    return 0;
}
