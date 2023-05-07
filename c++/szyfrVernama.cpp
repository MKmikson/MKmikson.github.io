#include <iostream>
// #include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> generujKlucz(int dlugosc) {
    vector<int> klucz(dlugosc);
    for (int i = 0; i < dlugosc; i++) {
        klucz[i] = rand() % 256;  // Generowanie losowych wartości bajtów między 0 a 255
    }
    return klucz;
}

vector<int> zaszyfruj(const string& tekst_jawny, const vector<int>& klucz) {
    vector<int> tekst_zaszyfrowany(tekst_jawny.size());
    for (int i = 0; i < tekst_jawny.size(); i++) {
        tekst_zaszyfrowany[i] = tekst_jawny[i] ^ klucz[i];  // Operacja XOR między bajtem tekstu jawnego i odpowiadającym mu bajtem klucza
    }
    return tekst_zaszyfrowany;
}

string odszyfruj(const vector<int>& tekst_zaszyfrowany, const vector<int>& klucz) {
    string tekst_jawny(tekst_zaszyfrowany.size(), '\0');
    for (int i = 0; i < tekst_zaszyfrowany.size(); i++) {
        tekst_jawny[i] = tekst_zaszyfrowany[i] ^ klucz[i];  // Operacja XOR między bajtem tekstu zaszyfrowanego i odpowiadającym mu bajtem klucza
    }
    return tekst_jawny;
}

int main() {

    ifstream tekst_zaszyfrowany('tekst.txt');
    ofstream wynik('wynik.txt');

    srand(time(NULL));  // Inicjalizacja generatora liczb losowych aktualnym czasem
    string tekst_jawny;

    while(!plikWe.eof()) {
        getline(tekst_jawny, tekst_jawny);
        vector<int> klucz = generujKlucz(tekst_jawny.size());

        vector<int> tekst_zaszyfrowany = zaszyfruj(tekst_jawny, klucz);
        cout << "Tekst zaszyfrowany: ";
        for (int i = 0; i < tekst_zaszyfrowany.size(); i++) {
            cout << tekst_zaszyfrowany[i] << " ";
        }
        cout << endl;

        string odszyfrowany_tekst = odszyfruj(tekst_zaszyfrowany, klucz);
        cout << "Odszyfrowany tekst: " << odszyfrowany_tekst << endl;

    }
    
    return 0;
}





// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <random>
// #include <ctime>
// using namespace std;
                            
// // funkcja kodująca wiadomość przy użyciu klucza
// string szyfrujVernama(string wiadomosc, string klucz) {
//     string szyfrogram = "";
//     for (int i = 0; i < wiadomosc.length(); i++) {

//         char c = wiadomosc[i] ^ klucz[i];
//         szyfrogram += c;
//         }
//         return szyfrogram;
//     }
                        
// // funkcja generująca losowy klucz o podanej długości
// string generujKlucz(int dlugosc) {
    
//     string klucz = "";
//     // generator liczb losowych
//     default_random_engine generator(time(0));
//     uniform_int_distribution(int) distribution(0, 255);
//     for (int i = 0; i < dlugosc; i++) {
//         // generowanie kolejnego bajtu klucza
//         int bajt = distribution(generator);
//         klucz += (char)bajt;
//     }
//     return klucz;
// }

// int main() {
//     ifstream plikWe("tekst.txt");
//     ofstream wynik("./wynik.txt");
//     string wiadomosc = "";

//     getline(plikWe, wiadomosc);
//     plikWe.close();
//     string klucz = generujKlucz(wiadomosc.length());
//     cout << "Wiadomość: " << wiadomosc << endl;
//     cout << "Klucz: " << klucz << endl;
//     string szyfrogram = szyfrujVernama(wiadomosc, klucz); 
//     wynik << "Zaszyfrowana wiadomość: " << szyfrogram << endl;
//     string odszyfrowanaWiadomosc = szyfrujVernama(szyfrogram, klucz);
//     wynik << "Odszyfrowana wiadomość: " << odszyfrowanaWiadomosc << endl;
//     wynik.close();
//     return 0;
// }
    