#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string szyfrujSzyfrCezara(string tekst, int przesuniecie) {
    string zaszyfrowanyTekst = "";
    for (int i = 0; i < tekst.length(); i++) {
        if (isupper(tekst[i])) {
            zaszyfrowanyTekst += char(int(tekst[i] + przesuniecie - 65) % 26 + 65);
        }
        else {
            zaszyfrowanyTekst += char(int(tekst[i] + przesuniecie - 97) % 26 + 97);
        }
    }
    return zaszyfrowanyTekst;
}

string deszyfrujSzyfrCezara(string zaszyfrowanyTekst, int przesuniecie) {
    string odszyfrowanyTekst = "";
    for (int i = 0; i < zaszyfrowanyTekst.length(); i++) {
        if (isupper(zaszyfrowanyTekst[i])) {
            odszyfrowanyTekst += char(int(zaszyfrowanyTekst[i] - przesuniecie - 65 + 26) % 26 + 65);
        }
        else {
            odszyfrowanyTekst += char(int(zaszyfrowanyTekst[i] - przesuniecie - 97 + 26) % 26 + 97);
        }
    }
    return odszyfrowanyTekst;
}

int main() {
    ifstream plikWe("./tekst.txt");
    ofstream wynik("./wynik.txt");
    string tekst;
    if (plikWe.is_open()) {
        getline(plikWe, tekst);
        plikWe.close();
    }
    else {
        cout << "Nie udalo sie otworzyc pliku tekst.txt.";
        return 0;
    }

    int przesuniecie;
    cout << "Podaj przesuniecie: ";
    cin >> przesuniecie;

    string zaszyfrowanyTekst = szyfrujSzyfrCezara(tekst, przesuniecie);
    wynik << "Zaszyfrowany tekst: " << zaszyfrowanyTekst << endl;

    string odszyfrowanyTekst = deszyfrujSzyfrCezara(zaszyfrowanyTekst, przesuniecie);
    wynik << "Odszyfrowany tekst: " << odszyfrowanyTekst << endl;
    wynik.close();
    return 0;
}
