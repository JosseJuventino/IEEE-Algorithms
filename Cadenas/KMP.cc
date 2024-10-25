/*
    El algoritmo de Knuth-Morris-Pratt (KMP) es un algoritmo de búsqueda de subcadenas que
    permite encontrar todas las ocurrencias de una cadena P en una cadena T en tiempo
    lineal. El algoritmo de KMP consiste en los siguientes pasos:
        1. Construye un arreglo de prefijos de la cadena P.
        2. Recorre la cadena T y la cadena P al mismo tiempo.
        3. Si los caracteres de la cadena T y la cadena P son iguales, incrementa los
        índices de ambas cadenas.
        4. Si los caracteres de la cadena T y la cadena P son diferentes, actualiza el
        índice de la cadena P utilizando el arreglo de prefijos.
        5. Repite los pasos 3 y 4 hasta que se haya recorrido toda la cadena T.

    Se usa este algoritmo para encontrar todas las ocurrencias de una cadena en otra cadena.
*/

#include <iostream>

int stringLength(const char* str) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

void computeLPSArray(char* pat, int M, int* lps) {
  int len = 0;
  lps[0] = 0;
  int i = 1;

  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}

void KMPSearch(char* pat, char* txt) {
  int M = stringLength(pat);
  int N = stringLength(txt);
  int lps[M];
  computeLPSArray(pat, M, lps);

  int i = 0;
  int j = 0;
  while (i < N) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }

    if (j == M) {
      std::cout << "Pattern found at index " << i - j << std::endl;
      j = lps[j - 1];
    } else if (i < N && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
  }
}

int main() {
  char txt[] = "abxabcabcaby";
  char pat[] = "abcaby";
  KMPSearch(pat, txt);
  return 0;
}
