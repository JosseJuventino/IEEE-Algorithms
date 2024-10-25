/*
    La busqueda binaria es un algoritmo de búsqueda que encuentra la posición de un
    valor en un arreglo ordenado. La búsqueda binaria compara el valor con el
    elemento en el medio del arreglo. Si el valor es igual al elemento en el medio,
    se ha encontrado el valor buscado. Si el valor es menor que el elemento en el
    medio, la búsqueda se realiza en la mitad inferior del arreglo. Si el valor es
    mayor que el elemento en el medio, la búsqueda se realiza en la mitad superior
    del arreglo. Este proceso se repite hasta que el valor sea encontrado o hasta
    que el subarreglo tenga longitud 0.

*/

#include <iostream>
using namespace std;

int busquedaBinaria(int arr[], int n, int objetivo) {
  int izquierda = 0, derecha = n - 1;
  while (izquierda <= derecha) {
    int medio = izquierda + (derecha - izquierda) / 2;
    if (arr[medio] == objetivo)
      return medio;  
    else if (arr[medio] < objetivo)
      izquierda = medio + 1;
    else
      derecha = medio - 1;
  }
  return -1;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << busquedaBinaria(arr, n, 7)
       << endl; 
  return 0;
}