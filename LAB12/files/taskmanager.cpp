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
        	for (int j = n - 1; j > i; j--) {
            		if (arr[j] < arr[j - 1]) {
                		int temp = arr[j];
                		arr[j] = arr[j - 1];
                		arr[j - 1] = temp;
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

struct Session {
    int clientCode;
    int duration;
    int year;
    int month;
};

void searchsessions(std::vector<Session>& sessions, int clientCode) {
    int maxDuration[11] = {0};
    int maxMonth[11] = {0};
    int yearCount[11] = {0};

    for (const auto& session : sessions) {
        if (session.clientCode == clientCode) {
            int yearIndex = session.year - 2000;
            yearCount[yearIndex] = 1;

            if (session.duration > maxDuration[yearIndex]) {
               	maxDuration[yearIndex] = session.duration;
                maxMonth[yearIndex] = session.month;
            }
		else if (session.duration == maxDuration[yearIndex]) {
                	if (session.month < maxMonth[yearIndex]) {
                    	maxMonth[yearIndex] = session.month;
                }
            }
        }
    }

    bool hasData = false;
    for (int year = 0; year < 11; ++year) {
        if (yearCount[year] == 1) {
            hasData = true;
            std::cout << "Короче у клиента " << clientCode << " макс. продолжительность это " << maxDuration[year] << ", " <<"год "<< (year + 2000) << ", " <<" месяц "<< maxMonth[year] << std::endl;
        }
    }

    if (!hasData) {
        std::cout << "Я ниче не нашел." << std::endl;
    }
}

void ExamTaskC15() {
	int clientCode;
    	std::cout << "Код клиента введи. ";
    	std::cin >> clientCode;

    	int n;
    	std::cout << "Колво записей введи. ";
    	std::cin >> n;

    	std::vector<Session> sessions;

    	std::cout << "Код клиента, продолжительность, год, месяц введи. " << std::endl;
    	for (int i = 0; i < n; ++i) {
        	Session session;
        	std::cin >> session.clientCode >> session.duration >> session.year >> session.month;
        	sessions.push_back(session);
    	}
	
    	searchsessions(sessions, clientCode);	
}
