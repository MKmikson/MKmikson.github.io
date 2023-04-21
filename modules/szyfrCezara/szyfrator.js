function cezar(s, k) { // s-tekst jawny, k-przesuniecie
    let result = ""; // tworzymy pusty ciąg, w którym będziemy umieszczać zaszyfrowany tekst
  
    // iterujemy po każdej literze w tekście jawnym
    for (let i = 0; i < s.length; i++) {
      let c = s.charCodeAt(i); // pobieramy kod ASCII aktualnej litery
  
      // Sprawdzamy, czy litera jest duża, mała lub poza alfabetem
      if (c >= 65 && c <= 90) { // duża litera
        result += String.fromCharCode((c - 65 + k) % 26 + 65); // dodajemy przesuniętą literę do zaszyfrowanego tekstu
      } else if (c >= 97 && c <= 122) { // mała litera
        result += String.fromCharCode((c - 97 + k) % 26 + 97); // dodajemy przesuniętą literę do zaszyfrowanego tekstu
      } else { // inny znak niż litera
        result += s.charAt(i); // dodajemy niezmieniony znak do zaszyfrowanego tekstu
      }
    }
  
    return result; // zwracamy zaszyfrowany tekst
  }
  

  function deszyfrujCezara(zaszyfrowanyTekst, k) {
    let result = ""; // tworzymy pusty ciąg, w którym będziemy umieszczać odszyfrowany tekst
  
    // iterujemy po każdej literze w zaszyfrowanym tekście
    for (let i = 0; i < zaszyfrowanyTekst.length; i++) {
      let c = zaszyfrowanyTekst.charCodeAt(i); // pobieramy kod ASCII aktualnej litery
  
      // Sprawdzamy, czy litera jest duża, mała lub poza alfabetem
      if (c >= 65 && c <= 90) { // duża litera
        result += String.fromCharCode((c - 65 - k + 26) % 26 + 65); // dodajemy odszyfrowaną literę do tekstu jawnego
      } else if (c >= 97 && c <= 122) { // mała litera
        result += String.fromCharCode((c - 97 - k + 26) % 26 + 97); // dodajemy odszyfrowaną literę do tekstu jawnego
      } else { // inny znak niż litera
        result += zaszyfrowanyTekst.charAt(i); // dodajemy niezmieniony znak do tekstu jawnego
      }
    }
  
    return result; // zwracamy odszyfrowany tekst
}  
  
function nowyOpis() {
  let inputV = document.getElementById('dane').value;
  document.getElementById('opis').innerHTML = inputV;
  }