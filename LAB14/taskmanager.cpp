#include <iostream>
#include <fstream>
#include <vector>
void Create() {
    std::vector<int> numbers;
    int num_amount;
    int num;

    std::cout << "сколько ты хочешь ввести чисел?" << std::endl;
    std::cin >> num_amount;
    for (int i = 0; i < num_amount; i++) {
        std::cin >> num;
        numbers.push_back(num);
    }

    std::ofstream outFile("files/thefile.bin", std::ios::binary);
    int num_count = numbers.size();
    outFile.write((char*)&num_count, sizeof(num_count));
    outFile.write((char*)numbers.data(), num_count * sizeof(int));
    outFile.close();
}
void File8() {
    std::ifstream infile("files/thefile.bin", std::ios::binary);
    infile.seekg(0, std::ios::end);

    std::streampos size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    double first;
    infile.read((char*)&first, sizeof(first));

    infile.seekg(size - sizeof(double));
    double last;
    infile.read((char*)&last, sizeof(last));

    infile.close();

    std::ofstream outfile("files/thefile8.bin", std::ios::binary);
    outfile.write((char*)&first, sizeof(first));
    outfile.write((char*)&last, sizeof(last));

    outfile.close();

    std::cout << "готово. все записано." << std::endl;
}

void File41() {
    std::ifstream infile("files/thefile.bin", std::ios::binary);
    std::vector<int> nums;
    int x;

    while (infile.read((char*)&x, sizeof(int))) {
        nums.push_back(x);
    }
    infile.close();

    std::vector<int> new_nums;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            new_nums.push_back(0);
            new_nums.push_back(0);
            new_nums.push_back(0);
        }
	else {
            new_nums.push_back(nums[i]);
        }
    }

    std::ofstream outfile("files/thefile41.bin", std::ios::binary | std::ios::trunc);
    for (int i = 0; i < new_nums.size(); i++) {
        outfile.write((char*)&new_nums[i], sizeof(int));
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