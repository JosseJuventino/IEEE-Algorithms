#include <iostream>
using namespace std;

void fusionar(int arr[], int inicio, int medio, int fin) {
  int n1 = medio - inicio + 1;
  int n2 = fin - medio;

  int izquierda[n1], derecha[n2];
  for (int i = 0; i < n1; i++) izquierda[i] = arr[inicio + i];
  for (int j = 0; j < n2; j++) derecha[j] = arr[medio + 1 + j];

  int i = 0, j = 0, k = inicio;
  while (i < n1 && j < n2) {
    if (izquierda[i] <= derecha[j]) {
      arr[k++] = izquierda[i++];
    } else {
      arr[k++] = derecha[j++];
    }
  }

  while (i < n1) arr[k++] = izquierda[i++];
  while (j < n2) arr[k++] = derecha[j++];
}

void mergesort(int arr[], int inicio, int fin) {
  if (inicio >= fin) return;
  int medio = inicio + (fin - inicio) / 2;
  mergesort(arr, inicio, medio);
  mergesort(arr, medio + 1, fin);
  fusionar(arr, inicio, medio, fin);
}

int main() {
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  mergesort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " "; 
  return 0;
}
