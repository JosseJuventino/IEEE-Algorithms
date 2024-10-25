/*
    El algoritmo de Rabin-Karp es un algoritmo de búsqueda de subcadenas que permite
    encontrar todas las ocurrencias de una cadena P en una cadena T en tiempo lineal.

    El algoritmo de Rabin-Karp consiste en los siguientes pasos:
        1. Calcula el hash de la cadena P y de las primeras m letras de la cadena T.
        2. Recorre la cadena T y calcula el hash de las siguientes m letras de la cadena T.
        3. Si el hash de la subcadena de la cadena T es igual al hash de la cadena P,
        compara la subcadena con la cadena P.
        4. Si las subcadenas son iguales, incrementa el contador de ocurrencias.
        5. Si las subcadenas son diferentes, actualiza el hash de la subcadena de la cadena T.
        6. Repite los pasos 2 a 5 hasta que se haya recorrido toda la cadena T.
*/

#include <iostream>

int stringLength(const char* str) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

void RabinKarp(char* pat, char* txt) {
  int M = stringLength(pat);
  int N = stringLength(txt);
  int d = 256;
  int q = 101;  // Prime number
  int h = 1;
  int p = 0;
  int t = 0;

  for (int i = 0; i < M - 1; i++) h = (h * d) % q;

  for (int i = 0; i < M; i++) {
    p = (d * p + pat[i]) % q;
    t = (d * t + txt[i]) % q;
  }

  for (int i = 0; i <= N - M; i++) {
    if (p == t) {
      bool match = true;
      for (int j = 0; j < M; j++) {
        if (txt[i + j] != pat[j]) {
          match = false;
          break;
        }
      }
      if (match) std::cout << "Pattern found at index " << i << std::endl;
    }
    if (i < N - M) {
      t = (d * (t - txt[i] * h) + txt[i + M]) % q;
      if (t < 0) t = (t + q);
    }
  }
}

int main() {
  char txt[] = "GEEKS FOR GEEKS";
  char pat[] = "GEEK";
  RabinKarp(pat, txt);
  return 0;
}
