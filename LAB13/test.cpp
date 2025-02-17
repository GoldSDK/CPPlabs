#include <iostream>
#include <vector>
#include <string>

int findk(int n, int k, std::string cur, int zeros) {
    int all = 0;
    for (int num = 0; num < k; num++) {
        if (num == 0) {
            if (zeros < 2) {
                all = all + findk(n, k, cur + '0', zeros + 1);
            }
        } 
        else {
            all = all + findk(n, k, cur + std::to_string(num), 0);
        }
    }
    return all;
}

void HomeDyn17() {
    int k, n;

    std::cout << "короче, введи k и n или типа того короче";
    std::cin >> k >> n;

    int res = findk(n, k, "", 0);
    std::cout << "колво чисел: " << res << std::endl;
}