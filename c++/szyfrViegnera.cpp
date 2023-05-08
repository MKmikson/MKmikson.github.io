// viegner działa

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string szyfrujVigenerea(string wiadomosc, string klucz) {
    string szyfr;
    int kluczIndex = 0;
    for (int i = 0; i < wiadomosc.length(); i++) {
        char c = toupper(wiadomosc[i]);
        if(c == ' '){
            szyfr += c;
        }
        else if (c >= 'A' && c <= 'Z') {
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
        if(c == ' '){
            wiadomosc += c;
        }
        else if (c >= 'A' && c <= 'Z') {
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
    ifstream plikWe("./tekst.txt");
    ofstream wynik("./wynik.txt");
    string tekst;
    string kod;
    cout << "Kod: ";
    cin >> kod;



   if (plikWe.is_open()) {
        while(!plikWe.eof()) {
            getline(plikWe, tekst);
            string zaszyfrowanyTekst = szyfrujVigenerea(tekst, kod);
            wynik << "Zaszyfrowany tekst: " << zaszyfrowanyTekst << endl;
  
            string odszyfrowanyTekst = deszyfrujVigenerea(zaszyfrowanyTekst, kod); 
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
