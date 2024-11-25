#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
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
void taskTwo(std::string STRING) {
	std::srand(time(0));
	int attempts = 0;
	std::string startingString = STRING;
	std::random_shuffle(STRING.begin(), STRING.end());
	while (STRING != startingString) {
		std::random_shuffle(STRING.begin(), STRING.end());
		std::cout << STRING << std::endl;
		attempts++;
	}
	std::cout << attempts << " attempts" << std::endl; 
}
void Five3(std::string STRING) {
	std::ifstream fle("FN1.txt");
	std::string fileString;
	while (std::getline(fle, fileString)) {
		for (int i = 0; i < fileString.length(); i++) {
			std::cout << fileString[i] << std::endl;
		}
	}
	fle.close();
}
