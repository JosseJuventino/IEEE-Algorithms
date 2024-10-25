/*
    El arreglo de sufijos de una cadena es un arreglo que contiene todos los
   sufijos de la cadena ordenados lexicográficamente. El algoritmo de
   construcción del arreglo de sufijos consiste en los siguientes pasos:
        1. Crea una estructura que contenga el índice del sufijo y el orden del
   sufijo.
        2. Inicializa un arreglo de sufijos con los sufijos de la cadena.
        3. Ordena los sufijos de acuerdo a su orden lexicográfico.
        4. Actualiza el orden de los sufijos.
        5. Repite los pasos 3 y 4 hasta que todos los sufijos estén ordenados.

    Sirve para ejercicios que requieran encontrar los sufijos de una cadena
    ordenados Un sufijo es una subcadena que empieza en una posición i y termina
    en la última posición de la cadena.

    El Suffix Array es un arreglo de índices que indica los sufijos de una
   cadena ordenados lexicográficamente (orden alfabético). Si tomamos la cadena
   "banana", sus sufijos son:

    0: banana
    1: anana
    2: nana
    3: ana
    4: na
    5: a

    El Suffix Array de la cadena "banana" es [5, 3, 1, 0, 4, 2].

    El Suffix Array se usa en algoritmos de búsqueda de subcadenas y en problemas
*/

#include <iostream>

int stringLength(const char* str) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

bool compareSuffix(const char* txt, int i, int j) {
  while (txt[i] != '\0' && txt[j] != '\0') {
    if (txt[i] != txt[j]) return txt[i] < txt[j];
    i++;
    j++;
  }
  return txt[i] == '\0';
}

void buildSuffixArray(char* txt) {
  int n = stringLength(txt);
  int suffixes[n];

  for (int i = 0; i < n; i++) suffixes[i] = i;

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!compareSuffix(txt, suffixes[i], suffixes[j])) {
        swap(suffixes[i], suffixes[j]);
      }
    }
  }

  std::cout << "Suffix Array: ";
  for (int i = 0; i < n; i++) std::cout << suffixes[i] << " ";
  std::cout << std::endl;
}

int main() {
  char txt[] = "banana";
  buildSuffixArray(txt);
  return 0;
}
