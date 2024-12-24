#include <iostream>
#include <fstream>
#include <vector>
void Sort1() {
	std::ofstream outFile("sort1_log.txt");

	int n;
    	std::cout << "Размер введи. ";
    	std::cin >> n;

    	std::vector<int> arr(n);

    	std::cout << "Элементы введи." << std::endl;
    	for (int i = 0; i < n; i++) {
        	std::cin >> arr[i];
    	}

	for (int i = 0; i < n - 1; i++) {
        	for (int j = 0; j < n - i - 1; j++) {
            		if (arr[j] > arr[j + 1]) {
                		int temp = arr[j];
                		arr[j] = arr[j + 1];
                		arr[j + 1] = temp;
            		}
        	}
		for (int i = 0; i < n; i++) {
			std::cout << arr[i] << " ";
			outFile << arr[i] << " ";
		}
		std::cout << std::endl;
		outFile << std::endl;
    	}

    	std::cout << "Готово. " << std::endl;
	outFile.close();
}
void Sort13() {
	
}
void ExamTaskC15() {
}
