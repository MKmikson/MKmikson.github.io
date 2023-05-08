// const { randomInt } = require('crypto');

function keyGenerator(view_text) {
  const bits = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];
  let key ="";
  for (let i = 0; i < view_text.length; i++) { 
    const bit_number = Math.random() * (bits.length);
    // console.log(bit_number, " -- bit_number");
    key += String.fromCharCode(view_text[i].charCodeAt() * bit_number);
    // console.log(String.fromCharCode(view_text[i].charCodeAt() * bit_number), " -- bit");
  }
  // console.log(key, " -- key");

  return key;
}

function hash(view_text, key) {
  let encrypted ="";
  for (let i = 0; i < view_text.length; i++){
    encrypted += String.fromCharCode(view_text[i].charCodeAt() + key[i].charCodeAt());
    // console.log(view_text[i].charCodeAt() + key[i].charCodeAt(), " -- encrypted");
  }

  return encrypted;
}

function decrypt(hashed_text, key) { 
  let decrypted ="";
  for (let i = 0; i < hashed_text.length; i++){
    decrypted += String.fromCharCode(hashed_text[i].charCodeAt() - key[i].charCodeAt());
    // console.log(String.fromCharCode(hashed_text[i].charCodeAt() - key[i].charCodeAt()), " -- decrypted");
  }

  return decrypted;
}


function displayS() {
    let line = document.getElementById('dane').value;
    
    
  if (document.getElementById('przes').value =="") {
    var key = keyGenerator(line);// generowanie klucza o takiej samej długości jak wiadomość
    console.log(key);
    document.getElementById('przes').value = key;
  } else {
    console.log("weszlo do ze istnieje klucz");
      var key = document.getElementById('przes').value;
      console.log(key, "---key");
  } 
    
    const hashedText = hash(line, key);  // szyfrowanie wiadomości przy użyciu klucza
    const decryptedText = decrypt(hashedText, key); // odszyfrowywanie wiadomości przy użyciu tego samego klucza

    if (line[0] == "-") {
        line = line.substr(1);
        document.getElementById('wynik').innerHTML = decrypt(line, key);;
    }
    else {
        document.getElementById('wynik').innerHTML = hashedText;
    }
    
  console.log('Wiadomość: ' + line);
  console.log('Klucz: ' + key);

  console.log('Zaszyfrowana wiadomość: ' + hashedText);
 
  console.log('Odszyfrowana wiadomość: ' + decryptedText);
  
  
}