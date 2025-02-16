#include <iostream>
#include "taskmanager.h"
int main() {
	int userChoice;
	std::cout << "Добро пожаловать в лабу 13. Какое задание хочешь выполнить?\n1. BackRec5\n2. HomeDyn2\n3. HomeDyn17" << std::endl;
	std::cin >> userChoice;
	while (userChoice < 1 || userChoice > 3) {
		std::cout << "Не хочу тебя расстраивать, но введенное значение неверно. От 1 до 3!!!!" << std::endl;
		std::cin >> userChoice;
	}
	switch (userChoice) {
		case 1:
			BackRec5();
			break;
		case 2:
			HomeDyn2();
			break;
		case 3:
			HomeDyn17();
			break;
	}
}
