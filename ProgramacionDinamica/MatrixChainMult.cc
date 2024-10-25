/*
    Este algoritmo resuelve el problema de multiplicar una cadena de matrices de
   la forma A1A2A3...An de tal forma que se minimice el número de
   multiplicaciones escalares. La idea es encontrar la forma óptima de agrupar
   las matrices para minimizar el número de multiplicaciones escalares.

    La solución al problema de la multiplicación de matrices en cadena se puede
   resolver mediante programación dinámica. La idea es crear una matriz dp de
   tamaño (n + 1) x (n + 1), donde n es el número de matrices en la cadena. La
   matriz dp[i][j] almacena el número mínimo de multiplicaciones escalares
   necesarias para multiplicar las matrices de la i-ésima a la j-ésima.

    La matriz se llena de la siguiente manera:
    dp[i][j] = min(dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j])

    Donde:
        - dp[i][j] es el número mínimo de multiplicaciones escalares necesarias
   para multiplicar las matrices de la i-ésima a la j-ésima.
        - dp[i][k] es el número mínimo de multiplicaciones escalares necesarias
   para multiplicar las matrices de la i-ésima a la k-ésima.
        - dp[k + 1][j] es el número mínimo de multiplicaciones escalares
   necesarias para multiplicar las matrices de la (k + 1)-ésima a la j-ésima.
        - p[i - 1] es el número de filas de la i-ésima matriz.
        - p[k] es el número de columnas de la k-ésima matriz.
        - p[j] es el número de columnas de la j-ésima matriz.

    La solución al problema es el valor de dp[1][n], que representa el número
   mínimo de multiplicaciones escalares necesarias para multiplicar todas las
   matrices en cadena.

    Complejidad del algoritmo:
        - Tiempo: O(n^3)
        - Espacio: O(n^2)
*/
#include <iostream>
using namespace std;

int matrixChainMultiplication(int dims[], int n) {
  int** dp = new int*[n];
  for (int i = 0; i < n; ++i) {
    dp[i] = new int[n];
    for (int j = 0; j < n; ++j) {
      dp[i][j] = 0;  // Inicializar a 0
    }
  }

  for (int l = 2; l < n; ++l) {
    for (int i = 0; i < n - l; ++i) {
      int j = i + l;
      dp[i][j] = 1e9;
      for (int k = i + 1; k < j; ++k) {
        int cost = dp[i][k] + dp[k][j] + dims[i] * dims[k] * dims[j];
        if (cost < dp[i][j]) {
          dp[i][j] = cost;
        }
      }
    }
  }

  int resultado = dp[0][n - 1];

  for (int i = 0; i < n; ++i) {
    delete[] dp[i];
  }
  delete[] dp;

  return resultado;
}

int main() {
  int dims[] = {1, 2, 3, 4};
  int n = sizeof(dims) / sizeof(dims[0]);
  cout << "El número mínimo de multiplicaciones es: "
       << matrixChainMultiplication(dims, n) << endl;
  return 0;
}

/*
    Otros algoritmos que son mas rapidos y eficientes para resolver el problema
    de multiplicacion de matrices en cadena son:
        - Algoritmo de Strassen
        - Algoritmo de Coppersmith-Winograd
        - Algoritmo de Schönhage-Strassen
        - Algoritmo de Williams
        - Algoritmo de Pan
*/