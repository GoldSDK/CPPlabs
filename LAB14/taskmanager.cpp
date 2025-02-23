#include <iostream>
#include <fstream>
void File8() {
    std::ifstream infile("files/input.bin", std::ios::binary);
    infile.seekg(0, std::ios::end);

    std::streampos size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    double first;
    infile.read((char*)&first, sizeof(first));

    infile.seekg(size - sizeof(double));
    double last;
    infile.read((char*)&last, sizeof(last));

    infile.close();

    std::ofstream outfile("files/output.bin", std::ios::binary);
    outfile.write((const char*)&first, sizeof(first));
    outfile.write((const char*)&last, sizeof(last));

    outfile.close();

    std::cout << "готово. все записано." << std::endl;
}

void File41() {
    std::cout << "Задание еще не готово. Возвращайся позже. Или нет." << std::endl;
}

void File50() {
    std::cout << "Задание еще не готово. Возвращайся позже. Или нет." << std::endl;
}

void Recur15() {
    std::cout << "Задание еще не готово. Возвращайся позже. Или нет." << std::endl;
}