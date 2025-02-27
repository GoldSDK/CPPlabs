#include <iostream>
#include <fstream>
#include <vector>
void Create() {
    std::vector<int> numbers;
    int num_amount;
    int num;

    std::cout << "сколько ты хочешь ввести чисел?" << std::endl;
    std::cin >> num_amount;

    std::cout << "делай." << std::endl;
    for (int i = 0; i < num_amount; i++) {
        std::cin >> num;
        numbers.push_back(num);
    }

    std::ofstream outFile("files/thefile.bin", std::ios::binary);
    int num_count = numbers.size();
    outFile.write((char*)&num_count, sizeof(num_count));
    outFile.write((char*)numbers.data(), num_count * sizeof(int));

    std::cout << "все твои " << num_amount << " чисел записаны в файл. почему все должен делать я..." << std::endl;
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

void File50_Create() {
    unsigned short amount;
    std::ofstream outfile1("files/s1.bin", std::ios::binary);
    std::ofstream outfile2("files/s2.bin", std::ios::binary);

    std::cout << "создай файлы s1 и s2. сколько чисел хочешь вписать для s1?" << std::endl;
    std::cin >> amount;

    std::cout << "делай." << std::endl;
    for (unsigned short i = 0; i < amount; i++) {
        unsigned short num;
        std::cin >> num;
        outfile1.write((char*)&num, sizeof(num));
    }

    std::cout << "сколько чисел хочешь вписать для s2?" << std::endl;
    std::cin >> amount;

    std::cout << "делай." << std::endl;
    for (unsigned short i = 0; i < amount; i++) {
        unsigned short num;
        std::cin >> num;
        outfile2.write((char*)&num, sizeof(num));
    }

    outfile1.close();
    outfile2.close();
};

void File50_Sort(std::vector<short>& array) {
    short n = array.size();
    bool swapped;

    while (swapped) {
        swapped = false;
        for (short i = 1; i < n; i++) {
            if (array[i - 1] > array[i]) {
                std::swap(array[i - 1], array[i]);
                swapped = true;
            }
        }
        n--;
    }
}

void File50() {
    File50_Create();
    
    std::vector<short> all_nums;
    std::ifstream infile1("files/s1.bin", std::ios::binary);
    std::ifstream infile2("files/s2.bin", std::ios::binary);
    std::ofstream outfile3("files/s3.bin", std::ios::binary);

    short current_num;
    while (infile1.read((char*)&current_num, sizeof(short))) {
        all_nums.push_back(current_num);
    }
    while (infile2.read((char*)&current_num, sizeof(short))) {
        all_nums.push_back(current_num);
    }

    File50_Sort(all_nums);

    for (short i = 0; i < all_nums.size(); i++) {
        outfile3.write((char*)&all_nums[i], sizeof(all_nums[i]));
    }
    outfile3.close();

    std::ifstream infile3("files/s3.bin", std::ios::binary);
    std::cout << "содержимое файла s3:" << std::endl;
    while (infile3.read((char*)&current_num, sizeof(short))) {
        std::cout << current_num << " ";
    }
    std::cout << std::endl;

    infile1.close();
    infile2.close();
    infile3.close();
}

void Recur15() {
    std::cout << "задание еще не готово. Возвращайся позже. Или нет." << std::endl;
}