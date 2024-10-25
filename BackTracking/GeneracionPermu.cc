/*
    Generacion de permutaciones es un problema clásico de backtracking. Dado un
    conjunto de elementos, se desea generar todas las posibles permutaciones de
    dichos elementos.

    Para generar las permutaciones, se puede utilizar un vector de booleanos para
    indicar si un elemento ya fue utilizado o no. En cada llamada recursiva, se
    verifica si un elemento ya fue utilizado, y si no lo fue, se marca como
    utilizado y se llama recursivamente con el siguiente elemento. Al regresar de
    la llamada recursiva, se desmarca el elemento para poder ser utilizado en otra
    permutación.

*/

#include <iostream>

void permute(char* str, int l, int r) {
  if (l == r)
    std::cout << str << std::endl;
  else {
    for (int i = l; i <= r; i++) {
      std::swap(str[l], str[i]);
      permute(str, l + 1, r);
      std::swap(str[l], str[i]);  // backtracking
    }
  }
}

int main() {
  char str[] = "ABC";
  int n = 3;
  permute(str, 0, n - 1);
  return 0;
}
