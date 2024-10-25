#include <iostream>
using namespace std;

void quicksort(int arr[], int bajo, int alto) {
  if (bajo >= alto) return;

  int pivote = arr[alto];
  int izquierda = bajo;

  for (int j = bajo; j < alto; ++j) {
    if (arr[j] < pivote) {
      swap(arr[izquierda], arr[j]);
      izquierda++;
    }
  }
  swap(arr[izquierda], arr[alto]);

  quicksort(arr, bajo, izquierda - 1);
  quicksort(arr, izquierda + 1, alto);
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  quicksort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}
