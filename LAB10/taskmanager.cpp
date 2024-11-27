#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
void ExamBegin96(std::string STRING) {
	std::string currentWord;
	int eCounter = 0;
	for (int i = 0; i < STRING.length(); i++) {
		if (!std::isspace(STRING[i])) {
			currentWord = currentWord + STRING[i];
			if (STRING[i] == 'E') {
				eCounter++;
			}
		}
		else {
			if (eCounter == 3) {
				std::cout << currentWord << std::endl;
			}
			currentWord = "";
			eCounter = 0;
		}
	}
	if (eCounter == 3) {
		std::cout << currentWord << std::endl;
	}
}
void shuffleStr(std::string &STRING) {
	char temp;
	int randomIndex;
	for (int i = 0; i < STRING.length(); i++) {
		randomIndex = std::rand() % STRING.length();
		temp = STRING[i];
		STRING[i] = STRING[randomIndex];
		STRING[randomIndex] = temp;
	}
}
void taskTwo(std::string STRING) {
	std::srand(time(0));
	int attempts = 0;
	std::string startingString = STRING;
	shuffleStr(STRING);
	std::cout << STRING << std::endl;
	while (STRING != startingString) {
		shuffleStr(STRING);
		std::cout << STRING << std::endl;
		attempts++;
	}
	std::cout << "и на это ушло " << attempts << " попыток..." << std::endl; 
}
void Five3(std::string STRING) {
	std::ifstream fle("FN1.txt");
	std::ofstream ole("FN2.txt");

	std::string fileString;
	std::string operand1, operand2;

	int parameter1, parameter2, answer;

	std::cout << "Считываю из файла:" << std::endl;
	while (std::getline(fle, fileString)) {
		std::cout << fileString << std::endl;
		for (int i = 0; i < 3; i++) {
			operand1 = operand1 + fileString[i];
			operand2 = operand2 + fileString[i + 4];
		}
		parameter1 = std::stoi(operand1);
		parameter2 = std::stoi(operand2);
		if (fileString[3] == '+') {
			answer = parameter1 + parameter2;
		}
		else {
			answer = parameter1 - parameter2;
		}
		ole << std::to_string(parameter1) << fileString[3] << std::to_string(parameter2) << "=" << std::to_string(answer) << "\n";
		operand1 = ""; operand2 = "";
	}

	std::cout << "Проверь файл FN2.txt чтобы увидеть ответы. Мог бы и калькулятором воспользоваться." << std::endl;

	// this fucking sucks :skull:

	fle.close();
	ole.close();
}
