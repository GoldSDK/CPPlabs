#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
	std::cout << "2" << std::endl;
}
void HomeDyn17() {
	std::cout << "3" << std::endl;
}
