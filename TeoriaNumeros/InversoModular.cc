/*
    El inverso modular de un número a módulo m es un número x tal que (a * x) % m = 1.
    El inverso modular existe si y solo si a y m son coprimos, es decir, si el máximo
    común divisor de a y m es 1.

    El inverso modular se puede encontrar utilizando el algoritmo de Euler para el cálculo
    del máximo común divisor. El algoritmo de Euler consiste en los siguientes pasos:
        1. Si b es 0, entonces el máximo común divisor de a y b es a.
        2. Calcula el máximo común divisor de b y a % b.
        3. Retorna el resultado del paso anterior.

    Por ejemplo si queremos encontrar el inverso modular de 3 módulo 11, primero calculamos
        MCD(3, 11) = 1
    Luego utilizamos el algoritmo de exponentiación rápida para encontrar el inverso modular:
        3^(-1) % 11 = 3^(11 - 2) % 11 = 3^9 % 11 = 9

*/

#include <iostream>
using namespace std;

int exponenciacionRapidaModular(int a, int b, int mod) {
  int resultado = 1;
  a = a % mod;

  while (b > 0) {
    if (b % 2 == 1) resultado = (resultado * a) % mod;
    b = b / 2;
    a = (a * a) % mod;
  }
  return resultado;
}

int inversoModular(int a, int m) {
  return exponenciacionRapidaModular(a, m - 2, m);  // Solo válido si m es primo
}

int main() {
  int a = 3, m = 11;  // 3 y 11 son coprimos, y 11 es primo
  cout << "Inverso modular de 3 mod 11 = " << inversoModular(a, m) << endl;
  return 0;
}
