/*
    Counting Sort es un algoritmo de ordenamiento que ordena los elementos de un
    arreglo contando el número de elementos con un valor determinado y colocando
    los elementos en un nuevo arreglo. El algoritmo de Counting Sort funciona
    solamente para arreglos con elementos no negativos y con un rango de valores
    conocido.

    El algoritmo de Counting Sort consiste en los siguientes pasos:
        1. Encuentra el valor máximo del arreglo.
        2. Crea un arreglo de conteo de tamaño max_val + 1 e inicialízalo con ceros.
        3. Incrementa el valor en la posición arr[i] del arreglo de conteo.
        4. Actualiza el arreglo de conteo sumando el valor actual con el valor
           anterior.
        5. Crea un arreglo de salida de tamaño n.
        6. Recorre el arreglo arr de derecha a izquierda y coloca el valor en la
           posición correcta del arreglo de salida.
        7. Copia el arreglo de salida al arreglo original.

    Complejidad del algoritmo en el peor caso:
        - Tiempo: O(n + k)
*/

#include <cstring>  // Para memset
#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
  int max_val = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max_val) max_val = arr[i];
  }

  int conteo[max_val + 1];
  memset(conteo, 0, sizeof(conteo));

  for (int i = 0; i < n; i++) conteo[arr[i]]++;

  int indice = 0;
  for (int i = 0; i <= max_val; i++) {
    while (conteo[i] > 0) {
      arr[indice++] = i;
      conteo[i]--;
    }
  }
}

int main() {
  int arr[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  countingSort(arr, n);
  for (int i = 0; i < n; i++) cout << arr[i] << " "; 
  return 0;
}
