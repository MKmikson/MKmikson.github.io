#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string szyfrujVernama(const string& wiadomosc, const string& klucz) {
    string szyfrogram;
    for (int i = 0; i < wiadomosc.length(); i++) {
        char c = wiadomosc[i] ^ klucz[i];  // Operacja XOR między kolejnymi bajtami wiadomości i klucza
        szyfrogram += c;
    }
    return szyfrogram;
}

string generujKlucz(int dlugosc) {
    string klucz;
    srand(time(NULL));  // Inicjalizacja generatora liczb losowych aktualnym czasem
    for (int i = 0; i < dlugosc; i++) {
        char bajt = rand() % 256;  // Generowanie losowych wartości bajtów między 0 a 255
        klucz += bajt;
    }
    return klucz;
}

int main() {
    ifstream plikWe("./tekst.txt");
    ofstream wynik("./wynik.txt");

    string wiadomosc;
    string klucz = generujKlucz(wiadomosc.length());

    if (plikWe.is_open()) {
        while(!plikWe.eof()) {
            getline(plikWe, wiadomosc);
            cout<<wiadomosc<<"--wiad"<<endl;
            string szyfrogram = szyfrujVernama(wiadomosc, klucz);
            cout<<"Klucz: "<<klucz<<endl;
            wynik << "Szyfrogram: " << szyfrogram << endl;
            wynik << "odszyfrowany tekst: " << szyfrujVernama(szyfrogram, klucz) << endl;
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



