#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void Graf1() {
    ifstream file("FileName.txt");
    if (!file.is_open()) {
        cout << "файл не открыт. наверное, его нет." << endl;
        return;
    }

    short n;
    file >> n;
    vector<short> degrees(n, 0);

    for (short i = 0; i < n; i++) {
        for (short j = 0; j < n; j++) {
            bool edge;
            file >> edge;
            if (i == j) {
                degrees[i] += 2 * edge;
            } else {
                degrees[i] += edge;
            }
        }
    }
    file.close();

    for (short i = 0; i < n; i++) {
        cout << degrees[i] << " ";
    }
    cout << endl;
}

void Graf4() {
    ifstream file("FileName.txt");
    if (!file.is_open()) {
        cout << "файл не открыт. наверное, его нет." << endl;
        return;
    }

    short n;
    file >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (short i = 0; i < n; i++) {
        for (short j = 0; j < n; j++) {
            file >> matrix[i][j];
        }
    }
    file.close();

    short k;
    cout << "откуда начинать: ";
    cin >> k;

    if (k < 0 || k >= n) {
        cout << "некорректный номер. смотри внимательнее" << endl;
        return;
    }

    vector<bool> visited(n, false);
    queue<short> q;

    visited[k] = true;
    q.push(k);

    while (!q.empty()) {
        short current = q.front();
        q.pop();
        cout << current << " ";

        for (short j = 0; j < n; j++) {
            if (matrix[current][j] != 0 && !visited[j]) {
                visited[j] = true;
                q.push(j);
            }
        }
    }
    cout << endl;
}

void Graf8() {
    ifstream file("FileName.txt");
    if (!file.is_open()) {
        cout << -1 << endl;
        return;
    }

    short n;
    file >> n;
    vector<vector<short>> graph(n, vector<short>(n));

    for (short i = 0; i < n; i++) {
        for (short j = 0; j < n; j++) {
            file >> graph[i][j];
        }
    }
    file.close();

    short K, L;
    cout << "Введите номер города K (от 1 до " << n << "): ";
    cin >> K;
    cout << "Введите минимальное количество пересадок L: ";
    cin >> L;

    if (K < 1 || K > n || L < 0) {
        cout << -1 << endl;
        return;
    }

    vector<short> dist(n, -1);
    queue<short> q;
    short start = K - 1;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        short current = q.front();
        q.pop();

        for (short neighbor = 0; neighbor < n; neighbor++) {
            if (graph[current][neighbor] == 1 && dist[neighbor] == -1) {
                dist[neighbor] = dist[current] + 1;
                q.push(neighbor);
            }
        }
    }

    vector<short> result;
    for (short i = 0; i < n; i++) {
        if (dist[i] == L + 1) {
            result.push_back(i + 1);
        }
    }

    sort(result.begin(), result.end());
    if (result.empty()) {
        cout << -1 << endl;
    } else {
        for (short city : result) {
            cout << city << " ";
        }
        cout << endl;
    }
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