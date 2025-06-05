#include <iostream>
#include <fstream>
using namespace std;

void Graf1() {

}

void Graf4() {

}

void Graf8() {

}

void CreateFileName() {
    ofstream file;
    short vert_amount;

    file.open("FileName.txt");

    cout << "сколько тебе нужно вершин?" << endl;
    cin >> vert_amount;

    file << vert_amount << endl;

    for (short i = 0; i < vert_amount; i++) {
        cout << "введи строку смежности для " << i << " вершины." << endl;
        for (short j = 0; j < vert_amount; j++) {
            bool has_edge;
            cin >> has_edge;
            file << has_edge << " ";
        }
        file << endl;
    }

    file.close();
    cout << "все готово. филенаме создан. почему все должен делать я..." << endl;
}