#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
void BackRec5() {
    	std::ifstream fin("files/input.txt");
    	int n, z;
    	fin >> n >> z;

    	std::vector<int> weights(n);
    	std::vector<int> values(n);

    	for (int i = 0; i < n; i++) {
        	fin >> weights[i];
    	}

    	for (int i = 0; i < n; i++) {
        	fin >> values[i];
    	}

    	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(z + 1, 0));

    	for (int i = 1; i <= n; i++) {
      		for (int w = 0; w <= z; ++w) {
            		if (weights[i - 1] > w) {
                		dp[i][w] = dp[i - 1][w];
            		}
			else {
                		dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            		}
        	}
    	}

    	std::vector<int> selected;
    	int currentWeight = z;
    	int totalValue = dp[n][z];
    	int totalWeight = 0;

    	for (int i = n; i >= 1; i--) {
        	if (dp[i][currentWeight] != dp[i - 1][currentWeight]) {
            		selected.push_back(i);
            		currentWeight -= weights[i - 1];
        	}
    	}

    	std::reverse(selected.begin(), selected.end());
    	totalWeight = z - currentWeight;

	std::cout << "ну короче, выбранные артефакты:" << std::endl;
    	for (int i = 0; i < selected.size(); i++) {
        	std::cout << selected[i] << " ";
    	}
	std::cout << std::endl;
    	std::cout << "общий вес: " << totalWeight << "\nобщая ценность: " << totalValue << std::endl;
}
void HomeDyn2() {
	std::cout << "задания еще нету. возвращайся позже." << std::endl;
}

std::string add(const std::string& a, const std::string& b) {
    std::string res;
    int lo = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || lo) {
        int sum = lo;
        if (i >= 0) {
		sum += a[i--] - '0';
	}
        if (j >= 0) {
		sum += b[j--] - '0';
	}
        lo = sum / 10;
        res.push_back((sum % 10) + '0');
    }

    std::reverse(res.begin(), res.end());
    return res;
}

std::string multiply(const std::string& a, int b) {
    std::string res;
    int lo = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        int mres = (a[i] - '0') * b + lo;
        lo = mres / 10;
        res.push_back((mres % 10) + '0');
    }
    while (lo) {
        res.push_back((lo % 10) + '0');
        lo /= 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

void HomeDyn17() {
    	int k, n;

	std::cout << "введи k и n или типа того." << std::endl;
    	std::cin >> k >> n;

    	std::string pr0 = std::to_string(k - 1);
    	std::string pr1 = "0";
    	std::string pr2 = "0";

    	for (int i = 2; i <= n; i++) {
        	std::string cur0 = multiply(add(add(pr0, pr1), pr2), k - 1);
        	std::string cur1 = pr0;
        	std::string cur2 = pr1;

        	pr0 = cur0;
        	pr1 = cur1;
        	pr2 = cur2;
    	}

    	std::string res = add(add(pr0, pr1), pr2);
    	std::cout << "короче, ответ " << res << std::endl;
}
