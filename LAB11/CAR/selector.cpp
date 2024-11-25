#include <iostream>
#include <vector>
#include "actionmanager.h"
int main() {
	int userSelection;

	std::cout << "День добрый. Добро пожаловать в автомобилер." << std::endl;
	while (userSelection != 6) {
		std::cout << "\nЧто ты хочешь сделать?\n1. Добавить машину\n2. Просмотреть машину\n3. Подсчет по марке\n4. Поиск по диапазону годов\n5. Подсчитать средний год всех машин\n6. Выйти" << std::endl;
		std::cin >> userSelection;
	
		while (userSelection <= 0 || userSelection > 6) {
			std::cout << "Эм. Ты это. Нормальное число выбери. Я уже все на экране написал так-то." << std::endl;
			std::cin >> userSelection;
		}
	
		switch (userSelection) {
			case 1:
				addCar();
				break;
			case 2:
				viewCar();
				break;
			case 3:
				countBrands();
				break;
			case 4:
				countYearRange();
				break;
			case 5:
				averageYear();
				break;
		}
	}
	return 0;
}
