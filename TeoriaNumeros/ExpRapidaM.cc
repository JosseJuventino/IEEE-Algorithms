/*
    La exponenciacion rapida es un algoritmo que permite calcular a^b en O(log b).
    El algoritmo de exponenciacion rapida consiste en los siguientes pasos:
        1. Si b es 0, retorna 1.
        2. Si b es impar, retorna a * a^(b - 1).
        3. Si b es par, retorna (a^(b / 2))^2.

    Se usa este algoritmo para ejercicios que requieran calcular a^b de manera eficiente.
*/

#include <iostream>
using namespace std;

int exponenciacionRapidaModular(int a, int b, int mod) {
  int resultado = 1;
  a = a % mod;

  while (b > 0) {
    if (b % 2 == 1)  
      resultado = (resultado * a) % mod;
    b = b / 2;         
    a = (a * a) % mod;  
  }
  return resultado;
}

int main() {
  int a = 2, b = 10, mod = 1000;
  cout << "2^10 % 1000 = " << exponenciacionRapidaModular(a, b, mod) << endl;
  return 0;
}
