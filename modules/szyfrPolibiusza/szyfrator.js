// Funkcja szyfrująca
function szyfrujPolibiusz(tekst) {
  const tabela = [
    ['A', 'B', 'C', 'D', 'E'],
    ['F', 'G', 'H', 'I', 'J'],
    ['K', 'L', 'M', 'N', 'O'],
    ['P', 'Q', 'R', 'S', 'T'],
    ['U', 'V', 'W', 'X', 'Y'],
    ['Z', ' ', '.', ',', '?', '!']
  ];

  tekst = tekst.toUpperCase();

  let szyfrogram = '';
  for (let i = 0; i < tekst.length; i++) {
    let litera = tekst[i];
    if (litera === 'J') {
      litera = 'I';
    }
    for (let j = 0; j < tabela.length; j++) {
      const pozycja = tabela[j].indexOf(litera);
      if (pozycja !== -1) {
        szyfrogram += (j+1).toString() + (pozycja+1).toString();
        break;
      }
    }
  }
  return szyfrogram;
}

// Funkcja deszyfrująca
function deszyfrujPolibiusz(szyfrogram) {
  const tabela = [
    ['A', 'B', 'C', 'D', 'E'],
    ['F', 'G', 'H', 'I', 'J'],
    ['K', 'L', 'M', 'N', 'O'],
    ['P', 'Q', 'R', 'S', 'T'],
    ['U', 'V', 'W', 'X', 'Y'],
    ['Z', ' ', '.', ',', '?', '!']
  ];

  let tekst = '';
  for (let i = 0; i < szyfrogram.length; i += 2) {
    const wiersz = parseInt(szyfrogram[i], 10) - 1;
    const kolumna = parseInt(szyfrogram[i+1], 10) - 1;
    tekst += tabela[wiersz][kolumna];
  }
  return tekst;
}

function displayS() {
  let wiadomosc = document.getElementById('dane').value;
  if (wiadomosc[0] == "-") {
    wiadomosc = wiadomosc.substr(1);
    console.log(wiadomosc);
    console.log(deszyfrujPolibiusz(wiadomosc));
    document.getElementById('wynik').innerHTML = deszyfrujPolibiusz(wiadomosc);
  }else {
    document.getElementById('wynik').innerHTML = szyfrujPolibiusz(wiadomosc);
  }

   
}