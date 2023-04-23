#include iostream
#include string
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
    string wiadomosc = "Tajna wiadomość";
    string klucz = generujKlucz(wiadomosc.length()); 
    cout << "Wiadomość: " << wiadomosc << endl;
    cout << "Klucz: " << klucz << endl;
    string szyfrogram = szyfrujVernama(wiadomosc, klucz); 
    cout << "Zaszyfrowana wiadomość: " << szyfrogram << endl;
    string odszyfrowanaWiadomosc = szyfrujVernama(szyfrogram, klucz);
    cout << "Odszyfrowana wiadomość: " << odszyfrowanaWiadomosc << endl;
    return 0;
}