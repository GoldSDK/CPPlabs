#include <iostream>
#include <string>
#include "taskmanager.h"
int main() {
	int taskChoice;
	std::string userString;

	std::cout << "добро пожаловать в лабу 10. введи свой стринг:" << std::endl;
	std::getline(std::cin, userString);

	std::cout << "очень содержательно. какое задание хочешь выполнить?\n1. ExamBegin96\n2. 2 задание (у него нет имени)\n3. Five3" << std::endl;
	std::cin >> taskChoice;

	while (taskChoice <= 0 || taskChoice > 3) {
		std::cout << "эмммм. я все доступные числа на экран написал. 1, 2 или 3!!!!!" << std::endl;
		std::cin >> taskChoice;
	} 

	switch (taskChoice) {
		case 1:
			ExamBegin96(userString);
			break;
		case 2:
			taskTwo(userString);
			break;
		case 3:
			Five3(userString);
			break;
	}

	return 0;
}
