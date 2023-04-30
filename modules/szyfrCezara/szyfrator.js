function szyfrujSzyfrCezara(tekst, przesuniecie) {
  let zaszyfrowanyTekst = "";
  for (let i = 0; i < tekst.length; i++) {
    let kodZnaku = tekst.charCodeAt(i);
    if (kodZnaku >= 65 && kodZnaku <= 90) {
      zaszyfrowanyTekst += String.fromCharCode(((kodZnaku - 65 + przesuniecie) % 26) + 65);
    } else if (kodZnaku >= 97 && kodZnaku <= 122) {
      zaszyfrowanyTekst += String.fromCharCode(((kodZnaku - 97 + przesuniecie) % 26) + 97);
    } else {
      zaszyfrowanyTekst += tekst.charAt(i);
    }
  }
  return zaszyfrowanyTekst;
}
function deszyfrujSzyfrCezara(zaszyfrowanyTekst, przesuniecie) {
  let odszyfrowanyTekst = "";
  for (let i = 0; i < zaszyfrowanyTekst.length; i++) {
    let kodZnaku = zaszyfrowanyTekst.charCodeAt(i);
    if (kodZnaku >= 65 && kodZnaku <= 90) {
      odszyfrowanyTekst += String.fromCharCode(((kodZnaku - 65 - przesuniecie + 26) % 26) + 65);
    } else if (kodZnaku >= 97 && kodZnaku <= 122) {
      odszyfrowanyTekst += String.fromCharCode(((kodZnaku - 97 - przesuniecie + 26) % 26) + 97);
    } else {
      odszyfrowanyTekst += zaszyfrowanyTekst.charAt(i);
    }
  }
  return odszyfrowanyTekst;
}

  
function displayS() {
  let przes = document.getElementById("przes").value;
  let inputV = document.getElementById('dane').value;
  if (przes < 0) {
    przes = -przes;
    console.log(inputV, przes , deszyfrujSzyfrCezara(inputV, przes) ,"---deszyfr");
    document.getElementById('wynik').innerHTML = deszyfrujSzyfrCezara(inputV, przes);
  } else {
    console.log(inputV, przes, szyfrujSzyfrCezara(inputV, przes), "---szyfr");
    document.getElementById('wynik').innerHTML = szyfrujSzyfrCezara(inputV, przes);
  }
  
  
  }