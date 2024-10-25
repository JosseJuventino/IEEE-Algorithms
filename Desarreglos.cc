/*
    En combinatoria, un desarreglo es una permutación de un conjunto de
    elementos en la que ningún elemento aparece en su posición original.

    Dado un número n, se puede calcular el número de desarreglos de n
    elementos mediante la fórmula:

    D(n) = n! * (1 - 1/1! + 1/2! - 1/3! + ... + (-1)^n * 1/n!)
    D(n) = (n - 1) * (D(n - 1) + D(n - 2))

    Si tenemos el conjunto {1, 2, 3}, las permutaciones posibles son:
    {1, 2, 3} No es un desarreglo
    {1, 3, 2} No es un desarreglo, el 1 está en su posición original
    {2, 1, 3} No es un desarreglo, el 3 está en su posición original
    {2, 3, 1} Es un desarreglo
    {3, 1, 2} Es un desarreglo
    {3, 2, 1} No es un desarreglo, el 2 está en su posición original
*/

#include <iostream>

int desarreglos(int n) {
  // Casos base: D(0) = 1 y D(1) = 0
  if (n == 0) return 1;
  if (n == 1) return 0;

  int prev = 1;     // D(0)
  int current = 0;  // D(1)

  // Calcular D(n) iterativamente usando la fórmula recursiva
  for (int i = 2; i <= n; ++i) {
    int next = (i - 1) *
               (prev + current);  // Fórmula: D(n) = (n-1) * (D(n-1) + D(n-2))
    prev = current;
    current = next;
  }

  return current;
}

int main() {
  int n;
  std::cout << "Introduce el valor de n: ";
  std::cin >> n;

  std::cout << "El número de desarreglos de " << n
            << " elementos es: " << desarreglos(n) << std::endl;

  return 0;
}