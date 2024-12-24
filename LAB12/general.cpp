#include <iostream>
#include "files/taskmanager.h"
int main() {
	int userChoice;
	
	std::cout << "Пламенно приветствуем в сортозавре. Какое задание хочешь выполнить?\n1. Sort1\n2. Sort13\n3. ExamTaskC15" << std::endl;
	std::cin >> userChoice;
	
	while (userChoice <= 0 || userChoice > 3) {
		std::cout << "Посмотри на список опций еще раз. А теперь на твой выбор. Ничего странного не замечаешь?" << std::endl;
		std::cin >> userChoice;
	}
	
	switch (userChoice) {
		case 1:
			Sort1();
			break;
		case 2:
			Sort13();
			break;
		case 3:
			ExamTaskC13();
			break;
	}
	return 0;
}
