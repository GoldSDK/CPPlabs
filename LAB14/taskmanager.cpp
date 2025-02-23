#include <iostream>
#include <fstream>
#include <vector>
void File8() {
    std::ifstream infile("files/file8/input.bin", std::ios::binary);
    infile.seekg(0, std::ios::end);

    std::streampos size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    double first;
    infile.read((char*)&first, sizeof(first));

    infile.seekg(size - sizeof(double));
    double last;
    infile.read((char*)&last, sizeof(last));

    infile.close();

    std::ofstream outfile("files/file8/output.bin", std::ios::binary);
    outfile.write((const char*)&first, sizeof(first));
    outfile.write((const char*)&last, sizeof(last));

    outfile.close();

    std::cout << "готово. все записано." << std::endl;
}

void File41() {
    std::ifstream infile("files/file41/input.bin", std::ios::binary);
    std::vector<int> nums;
    int x;

    while (infile.read((char*)&x, sizeof(int))) {
        nums.push_back(x);
    }
    infile.close();

    std::vector<int> new_nums;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            new_nums.push_back(0);
            new_nums.push_back(0);
            new_nums.push_back(0);
        }
	else {
            new_nums.push_back(nums[i]);
        }
    }

    std::ofstream outfile("files/file41/output.bin", std::ios::binary | std::ios::trunc);
    for (int i = 0; i < new_nums.size(); ++i) {
        outfile.write((const char*)&new_nums[i], sizeof(int));
    }
    std::cout << "готово. все заменено. или тип того короче да." << std::endl;
    outfile.close();
}

void File50() {
    std::cout << "Задание еще не готово. Возвращайся позже. Или нет." << std::endl;
}

void Recur15() {
    std::cout << "Задание еще не готово. Возвращайся позже. Или нет." << std::endl;
}
