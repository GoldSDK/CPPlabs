#include <iostream>
#include <string>

struct client {
    int clientCode;
    int year;
    int month;
    int duration;
};

int main() {
    int n;
    std::cout << "Пламенно приветствую в фитнессере. Введи колво клиентов: ";
    std::cin >> n;

    client clients[n];

    for (int i = 0; i < n; i++) {
        std::cout << "Введи данные для клиента " << (i + 1) << " (код клиента, год, номер месяца, продолжительность) В ЭТОМ ЖЕ ПОРЯДКЕ!: ";
        std::cin >> clients[i].clientCode >> clients[i].year >> clients[i].month >> clients[i].duration;
    }

    client minClient;
    int minDuration = 31;

    for (int i = 0; i < n; i++) {
        if (clients[i].duration <= minDuration) {
            minDuration = clients[i].duration;
            minClient = clients[i];
	}
    }
    std::cout << "минимальная продолжительность: " << minClient.duration << std::endl;
    std::cout << "год: " << minClient.year << std::endl;
    std::cout << "номер месяца: " << minClient.month << std::endl;

    return 0;
}
