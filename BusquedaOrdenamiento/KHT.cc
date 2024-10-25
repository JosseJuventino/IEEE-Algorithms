/*
    El Algoritmo de Quickselect es una variación de QuickSort. La idea es usar el
    mismo enfoque de particionamiento, dividiendo el arreglo alrededor de un pivote.
    Sin embargo, en lugar de ordenar ambas mitades, solo exploramos la mitad donde
    se encuentra el k-ésimo elemento más pequeño, ahorrando tiempo.

    Por ejemplo si tenemos el arreglo [12, 3, 5, 7, 4, 19, 26] y queremos encontrar el 
    segundo elemento más pequeño (k = 1), el algoritmo de Quickselect nos devolverá el
    valor 4. Ya que k = 1, el segundo elemento más pequeño es 4. la k es una variable que 
    se pasa como argumento a la función quickSelect y significa el k-ésimo elemento más pequeño.

    Es uno ya que el arreglo es 0-indexado, es decir, el primer elemento tiene índice 0. Y el 4 
    es el segundo elemento más pequeño en el arreglo, ya que el 3 es el más pequeño.
*/

#include <iostream>

// Función de intercambio
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

// Función de partición similar a la utilizada en QuickSort
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low;

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[high]);
  return i;
}

// Función de Quickselect para encontrar el k-ésimo elemento más pequeño
int quickSelect(int arr[], int low, int high, int k) {
  if (low <= high) {
    int pivotIndex = partition(arr, low, high);

    if (pivotIndex ==
        k)  // Si el pivote está en la posición k, lo hemos encontrado
      return arr[pivotIndex];
    else if (pivotIndex > k)  // Si el pivote está a la derecha de k, buscamos
                              // en la izquierda
      return quickSelect(arr, low, pivotIndex - 1, k);
    else  // Si el pivote está a la izquierda de k, buscamos en la derecha
      return quickSelect(arr, pivotIndex + 1, high, k);
  }
  return -1;  // Caso en que k esté fuera de los límites
}

int main() {
  int arr[] = {12, 3, 5, 7, 4, 19, 26};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k;

  std::cout << "Introduce el valor de k (0-indexado): ";
  std::cin >> k;

  if (k >= 0 && k < n) {
    int result = quickSelect(arr, 0, n - 1, k);
    std::cout << "El elemento " << k + 1 << " más pequeño es: " << result
              << std::endl;
  } else {
    std::cout << "El valor de k está fuera de los límites." << std::endl;
  }

  return 0;
}
