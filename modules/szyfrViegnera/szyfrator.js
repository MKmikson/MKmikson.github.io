function szyfrujVigenere(tekstJawny, klucz) {
    const alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // alfabet, którego używamy w szyfrze Vigenère'a
    let zaszyfrowanyTekst = ""; // zmienna, do której będziemy dodawać zaszyfrowane litery
  
    klucz = klucz.toUpperCase(); // zmieniamy klucz na wielkie litery, by ułatwić późniejszą pracę
  
    // iterujemy po każdej literze w tekście jawnym
    for (let i = 0, j = 0; i < tekstJawny.length; i++) {
      let litera = tekstJawny[i].toUpperCase(); // pobieramy kolejną literę z tekstu jawnego i zmieniamy na wielką literę
  
      // Sprawdzamy, czy litera jest literą alfabetu
      if (alfabet.includes(litera)) {
        let kluczLiczba = klucz.charCodeAt(j) - 65; // pobieramy kolejną literę klucza i zamieniamy na liczbę od 0 do 25
        let literaLiczba = litera.charCodeAt(0) - 65; // pobieramy liczbę odpowiadającą literze z alfabetu
        let zaszyfrowanaLiczba = (literaLiczba + kluczLiczba) % 26; // obliczamy numer zaszyfrowanej litery w alfabecie
        let zaszyfrowanaLitera = alfabet.charAt(zaszyfrowanaLiczba); // pobieramy odpowiadającą zaszyfrowanej liczbie literę alfabetu
        zaszyfrowanyTekst += zaszyfrowanaLitera; // dodajemy zaszyfrowaną literę do tekstu zaszyfrowanego
        j = (j + 1) % klucz.length; // przechodzimy do kolejnej litery klucza; jeśli przekroczyliśmy długość klucza, zaczynamy od początku
      } else {
        zaszyfrowanyTekst += litera; // jeśli to nie litera, dodajemy niezaszyfrowany znak do tekstu zaszyfrowanego
      }
    }
  
    return zaszyfrowanyTekst; // zwracamy tekst zaszyfrowany szyfrem Vigenère'a
  }

  
  function deszyfrujVigenere(zaszyfrowanyTekst, klucz) {
    const alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // alfabet, którego używamy w szyfrze Vigenère'a
    let tekstJawny = ""; // zmienna, do której będziemy dodawać odszyfrowane litery
  
    klucz = klucz.toUpperCase(); // zmieniamy klucz na wielkie litery, by ułatwić późniejszą pracę
  
    // iterujemy po każdej literze w zaszyfrowanym tekście
    for (let i = 0, j = 0; i < zaszyfrowanyTekst.length; i++) {
      let litera = zaszyfrowanyTekst[i].toUpperCase(); // pobieramy kolejną literę z zaszyfrowanego tekstu i zmieniamy na wielką literę
  
      // Sprawdzamy, czy litera jest literą alfabetu
      if (alfabet.includes(litera)) {
        let kluczLiczba = klucz.charCodeAt(j) - 65; // pobieramy kolejną literę klucza i zamieniamy na liczbę od 0 do 25
        let literaLiczba = litera.charCodeAt(0) - 65; // pobieramy liczbę odpowiadającą literze z alfabetu
        let odszyfrowanaLiczba = (literaLiczba - kluczLiczba + 26) % 26; // obliczamy numer odszyfrowanej litery w alfabecie
        let odszyfrowanaLitera = alfabet.charAt(odszyfrowanaLiczba); // pobieramy odpowiadającą odszyfrowanej liczbie literę alfabetu
        tekstJawny += odszyfrowanaLitera; // dodajemy odszyfrowaną literę do tekstu jawnej
        j = (j + 1) % klucz.length; // przechodzimy do kolejnej litery klucza; jeśli przekroczyliśmy długość klucza, zaczynamy od początku
      } else {
        tekstJawny += litera; // jeśli to nie litera, dodajemy nieodszyfrowany znak do tekstu jawnego
      }
    }
  
    return tekstJawny; // zwracamy tekst odszyfrowany szyfrem Vigenère'a
  }
  

function displayS() {
  let wiadomosc = document.getElementById('dane').value;
  var klucz = document.getElementById('przes').value;
  if (klucz[0] == "-") {
    klucz = klucz.substr(1);
    console.log(klucz);
    document.getElementById('wynik').innerHTML = deszyfrujVigenere(wiadomosc, klucz);
  } else {
    document.getElementById('wynik').innerHTML = szyfrujVigenere(wiadomosc, klucz);
  }
}