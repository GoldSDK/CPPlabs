#include <iostream>
#include <string>
#include <locale>
#include <limits>
using namespace std;

wchar_t encryptChar(wchar_t c, short shift) {
    if (c >= L'A' && c <= L'Z') {
        return (c - L'A' + shift) % 26 + L'A';
    }
    else if (c >= L'А' && c <= L'Я') {
        return (c - L'А' + shift) % 32 + L'А';
    }
    return c;
}

wchar_t decryptChar(wchar_t c, short shift) {
    if (c >= L'A' && c <= L'Z') {
        return (c - L'A' - shift + 26) % 26 + L'A';
    }
    else if (c >= L'А' && c <= L'Я') {
        return (c - L'А' - shift + 32) % 32 + L'А';
    }
    return c;
}

wstring encrypt(const wstring &text, short shift) {
    wstring encryptedText;
    for (wchar_t c : text) {
        encryptedText += encryptChar(c, shift);
    }
    return encryptedText;
}

wstring decrypt(const wstring &text, short shift) {
    wstring decryptedText;
    for (wchar_t c : text) {
        decryptedText += decryptChar(c, shift);
    }
    return decryptedText;
}

int main() {
    setlocale(LC_ALL, "");

    wstring text;
    short shift;
    short user_choice;

    wcout << L"меня зовут юлий цезарь. тебе надо зашифровать (1) или расшифровать (2)?" << endl;
    wcin >> user_choice;
    
    while (user_choice < 1 || user_choice > 2) {
        wcout << L"ниче не понял. говори по человечьи." << endl;
        wcin >> user_choice;
    }

    wcin.ignore(numeric_limits<streamsize>::max(), L'\n');

    wcout << L"введи строку. (последовательность символов)" << endl;
    getline(wcin, text);

    wcout << L"введи сдвиг." << endl;
    wcin >> shift;

    wstring result;
    switch(user_choice) {
        case 1:
            result = encrypt(text, shift);
            break;
        case 2:
            result = decrypt(text, shift);
            break;
    }

    wcout << L"фух. ну тебя меня заставил попотеть. результат: " << result << endl;

    return 0;
}
