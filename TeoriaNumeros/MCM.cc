/*
    Algoritmo para encontrar el MCM usando el MCD.
    Usando la formula
        MCM(a, b) = (a * b) / MCD(a, b)
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

int MCM(int a, int b) { return (a * b) / MCD(a, b); }

int main() {
  int a = 15, b = 20;
  cout << "MCM(15, 20) = " << MCM(a, b) << endl;
  return 0;
}
