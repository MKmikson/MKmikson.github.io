#include <iostream>
#include <string>
using namespace std;

string szyfrujCezarem(string wiadomosc, int klucz) {
    string wynik = "";
    for (int i = 0; i < wiadomosc.length(); i++) {
        char c = wiadomosc[i];
        if (isalpha(c)) {
            c = toupper(c);
            c = (((c - 65) + klucz) % 26) + 65;
        }
        wynik += c;
    }
    return wynik;
}
                        
string deszyfrujCezarem(string wiadomosc, int klucz) {
    string wynik = "";
    for (int i = 0; i < wiadomosc.length(); i++) {

        char c = wiadomosc[i];
        if (isalpha(c)) {
            c = toupper(c);
            c = (((c - 65) - klucz + 26) % 26) + 65;
        }
        wynik += c;
    }
    return wynik;
}


int main(){
    ifstream plikWe("./tekst.txt");
    ofstream wynik("./wynik.txt");
    string tekst;
    int przesuniecie;
    cout << "przesuniecie: ";
    cin >> przesuniecie;

    while(!plikWe.eof()) {
        getline(plikWe, tekst);
        wynik>>"Szyfruj cezarem: ">>szyfrujCezarem(tekst, przesuniecie);
        wynik>>"Deszyfruj Cezarem: ">>deszyfrujCezarem(tekst, przesuniecie);
    }

    plikWe.close();
    wynik.close();
    return 0;
}
// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// string szyfrujSzyfrCezara(string tekst, int przesuniecie) {
//     string zaszyfrowanyTekst = "";
//     for (int i = 0; i < tekst.length(); i++) {
//         if(tekst[i]===' 'or  tekst[i]===','or tekst[i]==='.'ortekst[i]==='"'){
//             cout << "blank: --"<<tekst[i]<<endl;
//             zaszyfrowanyTekst += tekst[i];
//         }
//         else if(isupper(tekst[i])) {
//             zaszyfrowanyTekst += char(int(tekst[i] + przesuniecie - 65) % 26 + 65);
//         }
//         else {
//             zaszyfrowanyTekst += char(int(tekst[i] + przesuniecie - 97) % 26 + 97);
//         }
//     }
//     return zaszyfrowanyTekst;
// }

// string deszyfrujSzyfrCezara(string zaszyfrowanyTekst, int przesuniecie) {
//     string odszyfrowanyTekst = "";
//     for (int i = 0; i < zaszyfrowanyTekst.length(); i++) {
//         if(tekst[i]===' 'or tekst[i]===','or tekst[i]==='.'or tekst[i]==='"'){
//             odszyfrowanyTekst += tekst[i];
//         }
//         else if (isupper(zaszyfrowanyTekst[i])) {
//             odszyfrowanyTekst += char(int(zaszyfrowanyTekst[i] - przesuniecie - 65 + 26) % 26 + 65);
//         }
//         else {
//             odszyfrowanyTekst += char(int(zaszyfrowanyTekst[i] - przesuniecie - 97 + 26) % 26 + 97);
//         }
//     }
//     return odszyfrowanyTekst;
// }

// int main() {
//     ifstream plikWe("./tekst.txt");
//     ofstream wynik("./wynik.txt");
//     string tekst;
//     if (plikWe.is_open()) {


//     }
//     else {
//         cout << "Nie udalo sie otworzyc pliku tekst.txt.";
//         return 0;
//     }

//     int przesuniecie;
//     cout << "Podaj przesuniecie: ";
//     cin >> przesuniecie;
//     while(!plikWe.eof()){

//             getline(plikWe, tekst);
//     string zaszyfrowanyTekst = szyfrujSzyfrCezara(tekst, przesuniecie);
//     wynik << "Zaszyfrowany tekst: " << zaszyfrowanyTekst << endl;

//     string odszyfrowanyTekst = deszyfrujSzyfrCezara(zaszyfrowanyTekst, przesuniecie);
//     wynik << "Odszyfrowany tekst: " << odszyfrowanyTekst << endl;
//     }
//     plikWe.close();
//     wynik.close();
//     return 0;
// }
