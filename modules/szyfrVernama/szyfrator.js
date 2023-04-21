function szyfrujVernama(tekst, klucz) {
    let zaszyfrowanyTekst = ""; // zmienna, do której będziemy dodawać zaszyfrowane litery
  
    // iterujemy po każdym znaku w tekście
    for (let i = 0; i < tekst.length; i++) {
      let litera = tekst[i].toUpperCase(); // pobieramy kolejną literę i zamieniamy ją na dużą literę
  
      // jeśli litera jest literą alfabetu, szyfrujemy ją, w przeciwnym razie zostawiamy niezmienioną
      if (/^[A-Z]$/.test(litera)) {
        let kluczIndex = i % klucz.length; // obliczamy indeks klucza dla bieżącej litery
  
        // generujemy klucz zaszyfrowania na podstawie wartości ASCII kolejnych znaków klucza
        let kluczZaszyfrowany = klucz.split("").map((ch, index) => {
          let kod = ch.charCodeAt(0);
          let kluczIndex = (i + index) % klucz.length;
          let kluczKod = klucz.charCodeAt(kluczIndex);
          let zaszyfrowanyKod = (kod + kluczKod - 65) % 26 + 65;
          return String.fromCharCode(zaszyfrowanyKod);
        }).join("");
  
        // obliczamy kod ASCII zaszyfrowanej litery
        let zaszyfrowanyKod = litera.charCodeAt(0) + kluczZaszyfrowany.charCodeAt(kluczIndex) - 130;
  
        // upewniamy się, że kod ASCII nie wykracza poza zakres liter alfabetu
        if (zaszyfrowanyKod > 90) {
          zaszyfrowanyKod -= 26;
        }
  
        // dodajemy zaszyfrowaną literę do zaszyfrowanego tekstu
        zaszyfrowanyTekst += String.fromCharCode(zaszyfrowanyKod);
      } else {
        zaszyfrowanyTekst += litera; // jeśli to nie litera alfabetu, dodajemy niezmienioną literę do zaszyfrowanego tekstu
      }
    }
  
    return zaszyfrowanyTekst; // zwracamy tekst zaszyfrowany szyfrem Vernama
  }
  
  function deszyfrujVernama(zaszyfrowanyTekst, klucz) {
    let odszyfrowanyTekst = ""; // zmienna, do której będziemy dodawać odszyfrowane litery
  
    // iterujemy po każdym znaku w zaszyfrowanym tekście
    for (let i = 0; i < zaszyfrowanyTekst.length; i++) {
      let litera = zaszyfrowanyTekst[i].toUpperCase(); // pobieramy kolejną literę zaszyfrowanego tekstu i zamieniamy ją na dużą literę
  
      // jeśli litera jest literą alfabetu, odszyfrowujemy ją, w przeciwnym razie zostawiamy niezmienioną
      if (/^[A-Z]$/.test(litera)) {
        let kluczIndex = i % klucz.length; // obliczamy indeks klucza dla bieżącej litery
  
        // generujemy klucz zaszyfrowania na podstawie wartości ASCII kolejnych znaków klucza
        let kluczZaszyfrowany = klucz.split("").map((ch, index) => {
          let kod = ch.charCodeAt(0);
          let kluczIndex = (i + index) % klucz.length;
          let kluczKod = klucz.charCodeAt(kluczIndex);
          let zaszyfrowanyKod = (kod + kluczKod - 65) % 26 + 65;
          return String.fromCharCode(zaszyfrowanyKod);
        }).join("");
  
        // obliczamy kod ASCII odszyfrowanej litery
        let odszyfrowanyKod = litera.charCodeAt(0) - kluczZaszyfrowany.charCodeAt(kluczIndex) + 65;
  
        // upewniamy się, że kod ASCII nie wykracza poza zakres liter alfabetu
        if (odszyfrowanyKod < 65) {
          odszyfrowanyKod += 26;
        }
  
        // dodajemy odszyfrowaną literę do odszyfrowanego tekstu
        odszyfrowanyTekst += String.fromCharCode(odszyfrowanyKod);
      } else {
        odszyfrowanyTekst += litera; // jeśli to nie litera alfabetu, dodajemy niezmienioną literę do odszyfrowanego tekstu
      }
    }
  
    return odszyfrowanyTekst; // zwracamy tekst odszyfrowany szyfrem Vernama
  }
  