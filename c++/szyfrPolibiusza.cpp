#include <iostream>
#include <string>
using namespace std;

// Szyfrator Polibiusza
string szyfrujPolibiusza(string wiadomosc) {
    string szyfr;
    char tabela[5][5] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'K'},
        {'L', 'M', 'N', 'O', 'P'},
        {'Q', 'R', 'S', 'T', 'U'},
        {'V', 'W', 'X', 'Y', 'Z'}
    };
    for (int i = 0; i < wiadomosc.length(); i++) {
        char c = toupper(wiadomosc[i]);
        if (c >= 'A' && c <= 'Z') {
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    if (tabela[row][col] == c) {
                        szyfr += to_string(row+1) + to_string(col+1);
                    }
                }
            }
        }
    }
    return szyfr;
}

// Deszyfrator Polibiusza
string deszyfrujPolibiusza(string szyfr) {
    string wiadomosc;
    char tabela[5][5] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'K'},
        {'L', 'M', 'N', 'O', 'P'},
        {'Q', 'R', 'S', 'T', 'U'},
        {'V', 'W', 'X', 'Y', 'Z'}
    };
    for (int i = 0; i < szyfr.length(); i += 2) {
        int row = szyfr[i] - '0' - 1;
        int col = szyfr[i+1] - '0' - 1;
        if (row >= 0 && row < 5 && col >= 0 && col < 5) {
            wiadomosc += tabela[row][col];
        }
    }
    return wiadomosc;
}

// Przykład użycia
int main() {
    string wiadomosc = "JASNOZIELONY";
    string szyfr = szyfrujPolibiusza(wiadomosc);
    string odszyfrowane = deszyfrujPolibiusza(szyfr);
    cout << "Wiadomość: " << wiadomosc << endl;
    cout << "Szyfr: " << szyfr << endl;
    cout << "Odszyfrowane: " << odszyfrowane << endl;
    return 0;
}
