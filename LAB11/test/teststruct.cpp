#include <iostream>
int main() {
	struct Student {
		int age;
		int grade;
	};
	Student mark = {15, 8};
	std::cout << mark.age << std::endl;
	return 0;
}
//end my suffering
