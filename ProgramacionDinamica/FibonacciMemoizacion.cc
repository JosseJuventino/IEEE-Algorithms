/*
    La memoización es una técnica de programación dinámica que consiste en
    almacenar los resultados de las subinstancias de un problema para evitar
    recalcularlos. En el caso de la sucesión de Fibonacci, la memoización
    permite reducir la complejidad de O(2^n) a O(n).

    En este caso, se implementa una solución recursiva para calcular el n-ésimo
    término de la sucesión de Fibonacci, utilizando un arreglo para almacenar
    los resultados de los términos ya calculados.

*/

#include <iostream>

const int MAX = 1000;  // Máximo tamaño del arreglo de memoización
int memo[MAX];         // Arreglo para almacenar los resultados ya calculados

// Función de Fibonacci con memoización
int fibonacciMemo(int n) {
  if (n <= 1) return n;

  if (memo[n] != -1) return memo[n];

  memo[n] = fibonacciMemo(n - 1) + fibonacciMemo(n - 2);
  return memo[n];
}

int main() {
  int n;
  std::cout << "Introduce el valor de n: ";
  std::cin >> n;

  for (int i = 0; i <= n; i++) {
    memo[i] = -1;
  }

  // Llamamos a la función de Fibonacci con memoización
  std::cout << "Fibonacci de " << n << " es: " << fibonacciMemo(n) << std::endl;

  return 0;
}
