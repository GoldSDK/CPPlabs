#include <iostream>
#include <string>
int main() {
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::string stroka, output;

	std::cout << "enter stroka:" << std::endl;
	std::getline(std::cin, stroka);

	output = stroka;

	for (int i = 0; i < stroka.length(); i++) {
		if (!std::isspace(stroka[i])) {
			if (stroka[i] == 'z') {
				output[i] = 'a';
			}
			else {
				output[i] = alphabet[alphabet.find(stroka[i] + 1)];
			}
		}
	}

	std::cout << output << std::endl;

	return 0;
}
