/*
    El algoritmo de Euclides para el cálculo del máximo común divisor de dos números enteros 
    positivos a y b se basa en la siguiente propiedad:
        Si a > b, entonces el máximo común divisor de a y b es igual al máximo 
        común divisor de b y a % b.
    El algoritmo de Euclides consiste en los siguientes pasos:
        1. Si b es 0, entonces el máximo común divisor de a y b es a.
        2. Calcula el máximo común divisor de b y a % b.
        3. Retorna el resultado del paso anterior.
    
    Se usa este algoritmo para ejercicios que requieran calcular el máximo común divisor 
    de dos números.
*/

#include <iostream>
using namespace std;

int MCD(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int a = 48, b = 18;
  cout << "MCD(48, 18) = " << MCD(a, b) << endl;
  return 0;
}
