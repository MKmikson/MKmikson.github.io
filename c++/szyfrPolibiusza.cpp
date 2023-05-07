// polibiusz działa

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string szyfrujSzyfrPolibiusza(string tekst) {
    string zaszyfrowanyTekst = "";
    for (int i = 0; i < tekst.length(); i++) {
        char litera = tolower(tekst[i]);
        if (litera == ' ') {
            zaszyfrowanyTekst += ' ';
        }
        else if (litera >= 'a' && litera <= 'z') {
            int wiersz = (litera - 'a') / 5 + 1;
            int kolumna = (litera - 'a') % 5 + 1;
            zaszyfrowanyTekst += to_string(wiersz) + to_string(kolumna);
        }
    }
    return zaszyfrowanyTekst;
}

string deszyfrujSzyfrPolibiusza(string zaszyfrowanyTekst) {
    string odszyfrowanyTekst = "";
    for (int i = 0; i < zaszyfrowanyTekst.length(); i += 2) {
        if (zaszyfrowanyTekst[i] == ' ') {
            odszyfrowanyTekst += ' ';
            i--;
        }
        else {
            int wiersz = zaszyfrowanyTekst[i] - '0';
            int kolumna = zaszyfrowanyTekst[i+1] - '0';
            char litera = 'a' + (wiersz - 1) * 5 + kolumna - 1;
            odszyfrowanyTekst += litera;
        }
    }
    return odszyfrowanyTekst;
}

int main() {
    ifstream plikWe("./tekst.txt");
    ofstream wynik("./wynik.txt");
    string tekst;
    if (plikWe.is_open()) {
        while(!plikWe.eof()) {
            getline(plikWe, tekst);
            string zaszyfrowanyTekst = szyfrujSzyfrPolibiusza(tekst);
            wynik << "Zaszyfrowany tekst: " << zaszyfrowanyTekst << endl;

            string odszyfrowanyTekst = deszyfrujSzyfrPolibiusza(zaszyfrowanyTekst);
            wynik << "Odszyfrowany tekst: " << odszyfrowanyTekst << endl;
        }
        plikWe.close();
    }
    else {
        cout << "Nie udalo sie otworzyc pliku tekst.txt.";
        return 0;
    }

    
    wynik.close();
    return 0;
}
