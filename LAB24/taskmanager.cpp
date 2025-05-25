#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> alphabet = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

string Cipher(string st, short sh) {
    for (short i = 0; i < st.length(); i++) {
        char current = st[i];
        if (isspace(current)) {

        }
        else {
            auto loc = find(alphabet.begin(), alphabet.end(), current);
            auto index = loc - alphabet.begin();
            cout << index << endl;
        }
    }
}

string Decipher(string st, short sh) {

}