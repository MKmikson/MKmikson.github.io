function szyfrujPolibiusz(tekst) {
    const tabela = [
      ["A", "B", "C", "D", "E"],
      ["F", "G", "H", "I", "K"],
      ["L", "M", "N", "O", "P"],
      ["Q", "R", "S", "T", "U"],
      ["V", "W", "X", "Y", "Z"]
    ]; // tablica reprezentująca tabelę szyfru Polibiusza
  
    let zaszyfrowanyTekst = ""; // zmienna, do której będziemy dodawać zaszyfrowane pary liter
  
    // iterujemy po każdej literze w tekście
    for (let i = 0; i < tekst.length; i++) {
      let litera = tekst[i].toUpperCase(); // pobieramy kolejną literę i zmieniamy na wielką literę
  
      // Sprawdzamy, czy litera jest literą alfabetu
      if (/[A-Z]/.test(litera)) {
        // szukamy pozycji litery w tabeli szyfru Polibiusza
        let pozycja = znajdzPozycje(litera, tabela);
  
        // pobieramy indeksy wiersza i kolumny
        let wiersz = pozycja[0] + 1;
        let kolumna = pozycja[1] + 1;
  
        // tworzymy zaszyfrowaną parę liter
        let para = `${wiersz}${kolumna}`;
  
        zaszyfrowanyTekst += para; // dodajemy zaszyfrowaną parę liter do zaszyfrowanego tekstu
      } else {
        zaszyfrowanyTekst += litera; // jeśli to nie litera, dodajemy niezaszyfrowany znak do zaszyfrowanego tekstu
      }
    }
  
    return zaszyfrowanyTekst; // zwracamy tekst zaszyfrowany szyfrem Polibiusza
  }
  
  // funkcja pomocnicza, która zwraca pozycję litery w tabeli Polibiusza
  function znajdzPozycje(litera, tabela) {
    for (let i = 0; i < tabela.length; i++) {
      for (let j = 0; j < tabela[i].length; j++) {
        if (tabela[i][j] === litera) {
          return [i, j];
        }
      }
    }
}
  
function deszyfrujPolibiusz(tekst) {
    const tabela = [
      ["A", "B", "C", "D", "E"],
      ["F", "G", "H", "I", "K"],
      ["L", "M", "N", "O", "P"],
      ["Q", "R", "S", "T", "U"],
      ["V", "W", "X", "Y", "Z"]
    ]; // tablica reprezentująca tabelę szyfru Polibiusza
  
    let odszyfrowanyTekst = ""; // zmienna, do której będziemy dodawać odszyfrowane litery
  
    // iterujemy po każdej parze liczb w tekście
    for (let i = 0; i < tekst.length; i += 2) {
      let liczby = tekst.substring(i, i + 2); // pobieramy kolejną parę liczb
  
      // Sprawdzamy, czy liczby są poprawne
      if (/^[1-5]{2}$/.test(liczby)) {
        // pobieramy indeksy wiersza i kolumny
        let wiersz = parseInt(liczby[0]) - 1;
        let kolumna = parseInt(liczby[1]) - 1;
  
        // odszyfrowujemy literę z tablicy Polibiusza
        let litera = tabela[wiersz][kolumna];
  
        odszyfrowanyTekst += litera; // dodajemy odszyfrowaną literę do odszyfrowanego tekstu
      } else {
        odszyfrowanyTekst += liczby; // jeśli to nie poprawna para liczb, dodajemy nieodszyfrowane liczby do odszyfrowanego tekstu
      }
    }
  
    return odszyfrowanyTekst; // zwracamy tekst odszyfrowany szyfrem Polibiusza
  }
  