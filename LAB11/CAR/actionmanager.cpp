#include <iostream>
#include <vector>
#include <string>

struct car {
	std::string brand;
	std::string model;
	int year;
};
std::vector<car> allCars;

void addCar() {
	car userCar;
	std::string userBrand, userModel;
	int userYear;

	std::cout << "Введи марку, модель, год машины (в этом же порядке!!!! слышишь):" << std::endl;
	std::cin >> userBrand >> userModel >> userYear;

	userCar = {userBrand, userModel, userYear};
	allCars.push_back(userCar);			
}

void viewCar() {
	int viewSelection;

	if (allCars.size() == 0) {
		std::cout << "Итак, для просмотра тебе доступно... ой! список пуст! видимо кто-то забыл занести в список машины, хотя это является буквально единственным предназначением программы. что за народ пошел." << std::endl;
	}
	else {
		std::cout << "Всего для просмотра доступно " << allCars.size() << " машин. Какую из этих тебе надо?" << std::endl;
		std::cin >> viewSelection;
		while (viewSelection > allCars.size() || viewSelection <= 0) {
			std::cout << "Боже чел. Нет тут такой машины." << std::endl;
			std::cin >> viewSelection;
		}
		
		std::cout << allCars[viewSelection - 1].brand << " | " << allCars[viewSelection - 1].model << " | " << allCars[viewSelection - 1].year << std::endl;
	}
}

void countBrands() {
	if (allCars.size() == 0) {
		std::cout << "Интересный ты человек. Как насчет того, что ты сначала откроешь список машин и попробуешь сам? поймешь с какой проблемой я столкнулся. там ничего нет." << std::endl;
	}
	else {
		std::string brandToCount;
		int brandCounter = 0;

		std::cout << "Ок. Какого бренда тебе посчитать машины? Почему все делать должен я..." << std::endl;
		std::cin >> brandToCount;
	
		for (int i = 0; i < allCars.size(); i++) {
			if (allCars[i].brand == brandToCount) {
				brandCounter++;
			}
		}

		std::cout << "В твоем списке присутствует ровно " << brandCounter << " машин с маркой " << brandToCount << ". Информативно." << std::endl;
	}
}

void countYearRange() {
	if (allCars.size() == 0) {
		std::cout << "Придержи сових коней. Лучше вместо диапазона сначала введи сам список." << std::endl;
	}
	else {
		int from, to;
	
		std::cout << "С какого по какой год тебе считать?" << std::endl;
		std::cin >> from >> to;

		for (int i = 0; i < allCars.size(); i++) {
 			if (allCars[i].year >= from && allCars[i].year <= to) {
				std::cout << allCars[i].brand << " | " << allCars[i].model << " | " << allCars[i].year << std::endl;
			}
		}		
	}
}

void averageYear() {
	if (allCars.size() == 0) {
		std::cout << "Вот это прикол. Как я должен тебе посчитать пустой список машин? на ноль поделить?" << std::endl;
	}
	else {
		int accumulator = 0;
		float result;
		for (int i = 0; i < allCars.size(); i++) {
			accumulator = accumulator + allCars[i].year;
		}
		result = (float)accumulator/(float)allCars.size();
		std::cout << "Средний год всех машин в списке равен: " << result << "\nЗачем это вообще кому-то надо?" << std::endl;
	}
}
