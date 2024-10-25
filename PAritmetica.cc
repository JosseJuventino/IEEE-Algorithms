/*
    Una progresión aritmética es una secuencia de números en la que la
    diferencia entre términos consecutivos es constante, y esa diferencia se llama
    la diferencia común d.

    El termino n-ésimo de una progresión aritmética se puede calcular mediante la
    fórmula:
    a_n = a_1 + (n - 1) * d

    Si a = 2, d = 3 y n = 5, entonces los primeros 5 términos de la progresión
    aritmética son:

    2, 5, 8, 11, 14

*/

#include <iostream>
using namespace std;

int enesimoTermino(int a1, int d, int n) { return a1 + (n - 1) * d; }

int sumaTerminos(int a1, int d, int n) {
  return (n * (2 * a1 + (n - 1) * d)) / 2;
}

int main() {
  int a1, d, n;

  cout << "Introduce el primer término (a1): ";
  cin >> a1;

  cout << "Introduce la diferencia común (d): ";
  cin >> d;

  cout << "Introduce el número de términos (n): ";
  cin >> n;

  int an = enesimoTermino(a1, d, n);
  cout << "El término número " << n << " de la progresión aritmética es: " << an
       << endl;

  int suma = sumaTerminos(a1, d, n);
  cout << "La suma de los primeros " << n << " términos es: " << suma << endl;

  return 0;
}
