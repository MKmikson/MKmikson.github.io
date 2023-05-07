// viegner działa


#include <iostream>
#include <string>
using namespace std;

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
    cout<<szyfr<<endl;
    return szyfr;
}

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
    cout << wiadomosc << endl;
    return wiadomosc;
}


int main(){
    ifstream plikWe("tekst.txt");
    ofstream wynik("wynik.txt");
    string tekst;
    string kod;

    cout << "kod: ";
    cin >> kod;

    while(!plikWe.eof()){
        getline(plikWe,tekst);
        wynik<<szyfrujVigenerea(tekst, kod)<<endl;
        wynik << deszyfrujVigenerea(tekst, kod) << endl;
    }
    plikWe.close();
    wynik.close();
    return 0;
}

// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// string szyfrujSzyfrVigenere(string tekst, string klucz) {
//     string zaszyfrowanyTekst = "";
//     int dlugoscKlucza = klucz.length();
//     for (int i = 0; i < tekst.length(); i++) {
//         char litera = tolower(tekst[i]);
//         if (litera >= 'a' && litera <= 'z') {
//             int przesuniecie = klucz[i % dlugoscKlucza] - 'a';
//             char zaszyfrowanaLitera = 'a' + (litera - 'a' + przesuniecie) % 26;
//             zaszyfrowanyTekst += zaszyfrowanaLitera;
//         }
//         else {
//             zaszyfrowanyTekst += litera;
//         }
//     }
//     return zaszyfrowanyTekst;
// }

// string deszyfrujSzyfrVigenere(string zaszyfrowanyTekst, string klucz) {
//     string odszyfrowanyTekst = "";
//     int dlugoscKlucza = klucz.length();
//     for (int i = 0; i < zaszyfrowanyTekst.length(); i++) {
//         char litera = tolower(zaszyfrowanyTekst[i]);
//         if (litera >= 'a' && litera <= 'z') {
//             int przesuniecie = klucz[i % dlugoscKlucza] - 'a';
//             char odszyfrowanaLitera = 'a' + (litera - 'a' - przesuniecie + 26) % 26;
//             odszyfrowanyTekst += odszyfrowanaLitera;
//         }
//         else {
//             odszyfrowanyTekst += litera;
//         }
//     }
//     return odszyfrowanyTekst;
// }

// int main() {
//     ifstream plikWe("tekst.txt");
//     ofstream wynik("wynik.txt");
//     string tekst;


//     string klucz;
//     cout << "Podaj klucz: ";
//     cin>>klucz;
//     while(!plikWe.eof()){
//         getline(plikWe, tekst);
//         string zaszyfrowanyTekst = szyfrujSzyfrVigenere(tekst, klucz);
//         wynik << "Zaszyfrowany tekst: " << zaszyfrowanyTekst << endl;
//         cout<<zaszyfrowanyTekst<<endl;


//         string odszyfrowanyTekst = deszyfrujSzyfrVigenere(zaszyfrowanyTekst, klucz);
//         wynik << "Odszyfrowany tekst: " << odszyfrowanyTekst << endl;

//         cout<<odszyfrowanyTekst<<endl;
//     }

//     plikWe.close();
//     wynik.close();
//     return 0;
// }
