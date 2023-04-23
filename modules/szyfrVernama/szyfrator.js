// funkcja kodująca wiadomość przy użyciu klucza
function szyfrujVernama(wiadomosc, klucz) {
  let szyfrogram = '';
  for (let i = 0; i < wiadomosc.length; i++) {
      // operacja XOR na kolejnych bajtach wiadomości i klucza
      let c = String.fromCharCode(wiadomosc.charCodeAt(i) ^ klucz.charCodeAt(i));
      szyfrogram += c;
  }
  return szyfrogram;
}

// funkcja generująca losowy klucz o podanej długości
function generujKlucz(dlugosc) {
  let klucz = '';
  // generator liczb losowych
  for (let i = 0; i < dlugosc; i++) {
      // generowanie kolejnego bajtu klucza
      let bajt = Math.floor(Math.random() * 256);
      klucz += String.fromCharCode(bajt);
  }
  return klucz;
}

function displayS() {
  let wiadomosc = document.getElementById('dane').value;

  if (document.getElementById('przes').value =="") {
    var klucz = generujKlucz(wiadomosc.length);// generowanie klucza o takiej samej długości jak wiadomość
    document.getElementById('przes').value = klucz;
  } else {
    console.log("weszlo do ze istnieje klucz");
    var klucz = document.getElementById('przes').value;
  } 

  console.log('Wiadomość: ' + wiadomosc);
  console.log('Klucz: ' + klucz);
  let szyfrogram = szyfrujVernama(wiadomosc, klucz); // szyfrowanie wiadomości przy użyciu klucza
  console.log('Zaszyfrowana wiadomość: ' + szyfrogram);
  let odszyfrowanaWiadomosc = szyfrujVernama(szyfrogram, klucz); // odszyfrowywanie wiadomości przy użyciu tego samego klucza
  console.log('Odszyfrowana wiadomość: ' + odszyfrowanaWiadomosc);
  
  document.getElementById('wynik').innerHTML = szyfrogram;
  }
// testowanie działania szyfru Vernama


