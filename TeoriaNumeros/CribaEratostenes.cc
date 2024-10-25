/*
    El algoritmo de la criba de Eratóstenes es un algoritmo que permite encontrar
    todos los números primos menores o iguales a un número entero n. El algoritmo
    consiste en los siguientes pasos:
        1. Crea un arreglo de booleanos de tamaño n + 1 e inicialízalo con true.
        2. Marca los números 0 y 1 como no primos.
        3. Para cada número i de 2 a n:
            1. Si el número i es primo, marca todos los múltiplos de i como no primos.
        4. Los números primos son aquellos que tienen un valor true en el arreglo.

    El algoritmo sirve para ejercicios que requieran encontrar los números primos
    menores o iguales a un número entero n.
*/

#include <iostream>
using namespace std;

const int N = 1000000; 
bool esPrimo[N + 1];

void cribaEratostenes(int n) {
  for (int i = 0; i <= n; i++) esPrimo[i] = true;
  esPrimo[0] = esPrimo[1] = false;  // 0 y 1 no son primos

  for (int p = 2; p * p <= n; p++) {
    if (esPrimo[p]) {
      for (int i = p * p; i <= n; i += p) esPrimo[i] = false;
    }
  }
}

int main() {
  int n = 50;
  cribaEratostenes(n);
  for (int i = 0; i <= n; i++) {
    if (esPrimo[i]) cout << i << " ";
  }
  cout << endl;
  return 0;
}
