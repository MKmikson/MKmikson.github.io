function zaszyfrujTekst(tekst, przesuniecie) {
  let zaszyfrowanyTekst = '';
  tekst = tekst.toLowerCase();
  for (let i = 0; i < tekst.length; i++) {
    let kodZnaku = tekst.charCodeAt(i);
    let przesunietyKodZnaku = kodZnaku + przesuniecie;
    
    if (tekst[i] === ' ') {
      zaszyfrowanyTekst += ' ';
      continue;
    }
    
    if (tekst[i] === 'ó') {
      przesunietyKodZnaku -= 32;
    }
    
    if (przesunietyKodZnaku > 122) {
      przesunietyKodZnaku -= 26;
    }
    
    let zaszyfrowanyZnak = String.fromCharCode(przesunietyKodZnaku);
    zaszyfrowanyTekst += zaszyfrowanyZnak;
  }
  
  return zaszyfrowanyTekst;
}

function odszyfrujTekst(tekst, przesuniecie) {
  let odszyfrowanyTekst = '';
  tekst = tekst.toLowerCase();
  for (let i = 0; i < tekst.length; i++) {
    let kodZnaku = tekst.charCodeAt(i);
    let przesunietyKodZnaku = kodZnaku - przesuniecie;
    
    if (tekst[i] === ' ') {
      odszyfrowanyTekst += ' ';
      continue;
    }
    
    if (tekst[i] === 'ó') {
      przesunietyKodZnaku += 32;
    }
    
    if (przesunietyKodZnaku < 97) {
      przesunietyKodZnaku += 26;
    }
    
    let odszyfrowanyZnak = String.fromCharCode(przesunietyKodZnaku);
    odszyfrowanyTekst += odszyfrowanyZnak;
  }
  
  return odszyfrowanyTekst;
}

// Przykładowe użycie szyfru i deszyfratora:

  
function displayS() {
  let tekstDoZaszyfrowania = document.getElementById('dane').value;
  let przesuniecie = Number(document.getElementById('przes').value);

  if (przesuniecie < 0) { 
    przesuniecie = -przesuniecie;
    console.log(tekstDoZaszyfrowania, przesuniecie);
    let odszyfrowanyTekst = odszyfrujTekst(tekstDoZaszyfrowania, przesuniecie);
    console.log(odszyfrowanyTekst); // Ala ma kota
    document.getElementById('wynik').innerHTML = odszyfrowanyTekst; //
  } else {
    console.log(tekstDoZaszyfrowania, przesuniecie);
    let zaszyfrowanyTekst = zaszyfrujTekst(tekstDoZaszyfrowania, przesuniecie);
    console.log(zaszyfrowanyTekst); // Dód pd nrwd
    document.getElementById('wynik').innerHTML = zaszyfrowanyTekst; //
  }
  



  }