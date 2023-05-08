#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string zaszyfrujTekst(string tekst, int przesuniecie) {
  string zaszyfrowanyTekst = "";
  int dlugosc = tekst.length();
  
  for (int i = 0; i < dlugosc; i++) {
    char znak = tolower(tekst[i]);
    int kodZnaku = znak;
    int przesunietyKodZnaku = kodZnaku + przesuniecie;
    
    if (znak == ' ') {
      zaszyfrowanyTekst += ' ';
      continue;
    }
    
    if (znak == 'ó') {
      przesunietyKodZnaku -= 32;
    }
    
    if (przesunietyKodZnaku > 122) {
      przesunietyKodZnaku -= 26;
    }
    
    char zaszyfrowanyZnak = static_cast<char>(przesunietyKodZnaku);
    zaszyfrowanyTekst += zaszyfrowanyZnak;
  }
  
  return zaszyfrowanyTekst;
}

string odszyfrujTekst(string tekst, int przesuniecie) {
  string odszyfrowanyTekst = "";
  int dlugosc = tekst.length();
  
  for (int i = 0; i < dlugosc; i++) {
    char znak = tolower(tekst[i]);
    int kodZnaku = znak;
    int przesunietyKodZnaku = kodZnaku - przesuniecie;
    
    if (znak == ' ') {
      odszyfrowanyTekst += ' ';
      continue;
    }
    
    if (znak == 'ó') {
      przesunietyKodZnaku += 32;
    }
    
    if (przesunietyKodZnaku < 97) {
      przesunietyKodZnaku += 26;
    }
    
    char odszyfrowanyZnak = static_cast<char>(przesunietyKodZnaku);
    odszyfrowanyTekst += odszyfrowanyZnak;
  }
  
  return odszyfrowanyTekst;
}

int main() {
    ifstream plikWe("./tekst.txt");
    ofstream wynik("./wynik.txt");
  string tekst;
  int przesuniecie;
  cout << "przesuniecie: ";
  cin >> przesuniecie;

  if (plikWe.is_open()) {
        while(!plikWe.eof()) {
            getline(plikWe, tekst);
            string zaszyfrowanyTekst = zaszyfrujTekst(tekst, przesuniecie);
            wynik << "Zaszyfrowany tekst: " << zaszyfrowanyTekst << endl;
  
            string odszyfrowanyTekst = odszyfrujTekst(zaszyfrowanyTekst, przesuniecie);
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
