/*
    Los Números de Catalán cuentan el número de formas en las que se pueden
   asociar correctamente ciertos elementos. Un ejemplo clásico es el número de
   maneras de dividir un polígono en triángulos utilizando diagonales. Además,
   estos números aparecen en muchos otros contextos combinatorios.

    La forma más común de calcular los números de Catalán es mediante la
    fórmula:

    C(n) = (2n)! / (n! * (n + 1)!)

    Los números de Catalán aparecen en problemas combinatorios relacionados con
    estructuras recursivas, como los árboles binarios, emparejamientos de
    paréntesis, caminos en una cuadrícula, y más.

*/

#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
  unsigned long long fact = 1;
  for (int i = 2; i <= n; ++i) {
    fact *= i;
  }
  return fact;
}

unsigned long long catalan(int n) {
  unsigned long long result =
      factorial(2 * n) / (factorial(n + 1) * factorial(n));
  return result;
}

int main() {
  int n;

  cout << "Introduce el valor de n: ";
  cin >> n;

  cout << "El número de Catalán C_" << n << " es: " << catalan(n) << endl;

  return 0;
}
