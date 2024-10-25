/*
El objetivo es implementar una función que toma dos números enteros no negativos
x y, y devuelve el resultado de cambiar (flipping) todos los bits de x que están
establecidos en 1 en ambos x y y.

Por ejemplo, si x = 10 (1010 en binario) y y = 6 (0110 en binario), el resultado
de cambiar los bits de x que están establecidos en 1 en ambos x y y sería 12
(1100 en binario).

Para resolver este problema, podemos utilizar la operación XOR entre x e y para
encontrar los bits que están establecidos en 1 en ambos números. Luego, podemos
usar la operación XOR entre el resultado anterior y x para cambiar los bits de x
que están establecidos en 1 en ambos x e y.

La función que implementa esta solución se muestra a continuación:
*/

#include <iostream>

using namespace std;

int flipBits(int x, int y) {
  int mask =
      x & y;  // & es un operador de bits que devuelve 1 si ambos bits son 1
  int result = x ^ mask; // ^ es un operador de bits que devuelve 1 si los bits son diferentes
  return result;
}

int main() {
  int T;   
  cin >> T; 
  for (int i = 0; i < T; i++) {
    int x, y;
    cin >> x >> y;  
    cout << flipBits(x, y)
         << endl; 
  }
  return 0;
}