#include <iostream>
#include <string>
using namespace std;

// Szyfrator Vigenere'a
string szyfrujVigenerea(string wiadomosc, string klucz) {
    string szyfr;
    int kluczIndex = 0;
    for (int i = 0; i < wiadomosc.length(); i++) {
        char c = toupper(wiadomosc[i]);
        if (c >= 'A' && c <= 'Z') {
            char kluczChar = toupper(klucz[kluczIndex % klucz.length()]);
            int kluczOffset = kluczChar - 'A';
            char szyfrChar = ((c - 'A' + kluczOffset) % 26) + 'A';
            szyfr += szyfrChar;
            kluczIndex++;
        }
    }
    return szyfr;
}

// Deszyfrator Vigenere'a
string deszyfrujVigenerea(string szyfr, string klucz) {
    string wiadomosc;
    int kluczIndex = 0;
    for (int i = 0; i < szyfr.length(); i++) {
        char c = toupper(szyfr[i]);
        if (c >= 'A' && c <= 'Z') {
            char kluczChar = toupper(klucz[kluczIndex % klucz.length()]);
            int kluczOffset = kluczChar - 'A';
            char wiadomoscChar = ((c - 'A' - kluczOffset + 26) % 26) + 'A';
            wiadomosc += wiadomoscChar;
            kluczIndex++;
        }
    }
    return wiadomosc;
}

// Przykład użycia
int main() {
    string wiadomosc = "JASNOZIELONY";
    string klucz = "KOD";
    string szyfr = szyfrujVigenerea(wiadomosc, klucz);
    string odszyfrowane = deszyfrujVigenerea(szyfr, klucz);
    cout << "Wiadomość: " << wiadomosc << endl;
    cout << "Klucz: " << klucz << endl;
    cout << "Szyfr: " << szyfr << endl;
    cout << "Odszyfrowane: " << odszyfrowane << endl;
    return 0;
}