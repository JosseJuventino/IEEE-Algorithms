/*
    You should implement a function that takes as argument an array of 
    N words (strings) representing a text. You should format the text on multiple
    lines such that each line has length K and is justified.

    Return as many words as possible on each line and use extra spaces between words
    when needed to achieve a line length of K. The spaces should be evenly distributed 
    if possible. If the number of spaces is not divisible by the number of gaps between 
    the words you should choose to add more spaces between the words to the left.
    The last line should not be justified, but aligned to the left.

*/

#include <iostream>
using namespace std;

// Función para justificar el texto
void justifyText(string words[], int N, int K) {
  string currentLine;
  int numWords = 0;

  for (int i = 0; i < N; i++) {
    string word = words[i];

    // Si agregar la palabra excede la longitud K
    if (currentLine.length() + numWords + word.length() > K) {
      int totalSpaces = K - currentLine.length();
      int gaps = numWords - 1;  // Número de espacios entre palabras

      // Si hay solo una palabra, simplemente agregarla
      if (gaps == 0) {
        cout << currentLine << endl;
      } else {
        // Espacios adicionales a distribuir
        int spacesPerGap = totalSpaces / gaps;
        int extraSpaces = totalSpaces % gaps;

        // Justificar la línea
        string justifiedLine;
        for (int j = 0; j < numWords; j++) {
          justifiedLine += words[i - numWords + j];  // Palabras

          // Añadir espacios
          if (j < gaps) {
            for (int s = 0; s < spacesPerGap; s++) {
              justifiedLine += ' ';
            }
            if (extraSpaces > 0) {
              justifiedLine += ' ';  // Añadir un espacio extra
              extraSpaces--;
            }
          }
        }
        cout << justifiedLine << endl;
      }

      // Reiniciar para la nueva línea
      currentLine = word;
      numWords = 1;
    } else {
      // Agregar palabra a la línea actual
      if (!currentLine.empty()) {
        currentLine += ' ';
      }
      currentLine += word;
      numWords++;
    }
  }

  // Agregar la última línea (sin justificar)
  if (!currentLine.empty()) {
    cout << currentLine << endl;
  }
}

int main() {
  int N, K;
  cin >> N >> K;      // N es el número de palabras y K es la longitud de la línea
  string words[100];  // Suponiendo un máximo de 100 palabras

  // Leer las palabras
  for (int i = 0; i < N; i++) {
    cin >> words[i];
  }

  // Justificar el texto
  justifyText(words, N, K);

  return 0;
}
