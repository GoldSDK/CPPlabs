#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void BackRec5() {
    std::ifstream data("files/input.txt");
    int n, z;
    data >> n >> z;

    std::vector<int> wgt(n), prc(n);
    for (int i = 0; i < n; i++) {
        data >> wgt[i];
    }
    for (int i = 0; i < n; i++) {
        data >> prc[i];
    }
		
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(z + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= z; w++) {
            if (wgt[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - wgt[i - 1]] + prc[i - 1]);
            }
			else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    std::vector<int> chosen;
    int currwgt = z;

    for (int i = n; i >= 1; i--) {
        if (dp[i][currwgt] != dp[i - 1][currwgt]) {
            chosen.push_back(i);
            currwgt -= wgt[i - 1];
        }
    }

    std::reverse(chosen.begin(), chosen.end());
    int finalwgt = z - currwgt;
    int finalprc = dp[n][z];

    std::cout << "короче, выбранные артефакты: ";
    for (int i = 0; i < chosen.size(); i++) {
        std::cout << chosen[i] << " ";
    }
    std::cout << "\nобщий вес: " << finalwgt << "\nобщая ценность: " << finalprc << std::endl;
}

void HomeDyn2() {
	std::cout << "задания еще нету. возвращайся позже." << std::endl;
}

void HomeDyn17() {
	std::cout << "задания еще нету. возвращайся позже." << std::endl;
}