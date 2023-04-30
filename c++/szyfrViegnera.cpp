#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string szyfrujSzyfrVigenere(string tekst, string klucz) {
    string zaszyfrowanyTekst = "";
    int dlugoscKlucza = klucz.length();
    for (int i = 0; i < tekst.length(); i++) {
        char litera = tolower(tekst[i]);
        if (litera >= 'a' && litera <= 'z') {
            int przesuniecie = klucz[i % dlugoscKlucza] - 'a';
            char zaszyfrowanaLitera = 'a' + (litera - 'a' + przesuniecie) % 26;
            zaszyfrowanyTekst += zaszyfrowanaLitera;
        }
        else {
            zaszyfrowanyTekst += litera;
        }
    }
    return zaszyfrowanyTekst;
}

string deszyfrujSzyfrVigenere(string zaszyfrowanyTekst, string klucz) {
    string odszyfrowanyTekst = "";
    int dlugoscKlucza = klucz.length();
    for (int i = 0; i < zaszyfrowanyTekst.length(); i++) {
        char litera = tolower(zaszyfrowanyTekst[i]);
        if (litera >= 'a' && litera <= 'z') {
            int przesuniecie = klucz[i % dlugoscKlucza] - 'a';
            char odszyfrowanaLitera = 'a' + (litera - 'a' - przesuniecie + 26) % 26;
            odszyfrowanyTekst += odszyfrowanaLitera;
        }
        else {
            odszyfrowanyTekst += litera;
        }
    }
    return odszyfrowanyTekst;
}

int main() {
    ifstream plikWe("tekst.txt");
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

    string klucz;
    cout << "Podaj klucz: ";
    getline(cin, klucz);

    string zaszyfrowanyTekst = szyfrujSzyfrVigenere(tekst, klucz);
    wynik << "Zaszyfrowany tekst: " << zaszyfrowanyTekst << endl;

    string odszyfrowanyTekst = deszyfrujSzyfrVigenere(zaszyfrowanyTekst, klucz);
    wynik << "Odszyfrowany tekst: " << odszyfrowanyTekst << endl;
    wynik.close();
    return 0;
}
