/*
    El problema de la mochila es un problema de optimización combinatoria, en el
    que se busca una selección de elementos de un conjunto finito de manera que
    quepan en una mochila con capacidad limitada y maximicen el valor total de
   los elementos seleccionados.

    Cada elemento tiene un peso y un valor asociado, y la mochila tiene una
    capacidad máxima. El objetivo es seleccionar un subconjunto de elementos de
    manera que la suma de los pesos no exceda la capacidad de la mochila y el
   valor total sea máximo.

    La formulación matemática del problema de la mochila es la siguiente:
    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i]] + value[i])

    Donde:
    - dp[i][w] es el valor máximo que se puede obtener con los primeros i
   elementos y una capacidad w.

    - weight[i] es el peso del i-ésimo elemento.

    - value[i] es el valor del i-ésimo elemento.

    - dp[i - 1][w] es el valor máximo que se puede obtener sin incluir el
   i-ésimo elemento.

    - dp[i - 1][w - weight[i]] + value[i] es el valor máximo que se puede
   obtener

    incluyendo el i-ésimo elemento.
*/

#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& peso, vector<int>& valor, int n) {
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (peso[i - 1] <= w) {
        dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - peso[i - 1]] + valor[i - 1]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  return dp[n][W];
}

int main() {
  vector<int> peso = {1, 3, 4, 5};
  vector<int> valor = {1, 4, 5, 7};
  int W = 7;
  int n = peso.size();
  cout << "El valor máximo en la mochila es: " << knapsack(W, peso, valor, n)
       << endl;
  return 0;
}