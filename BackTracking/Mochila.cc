/*
    El codigo consiste en un algoritmo de backtracking que resuelve el problema
    de la mochila. Dado un conjunto de elementos, cada uno con un peso y un valor,
    se desea determinar la combinación de elementos que maximice el valor total
    sin exceder un peso máximo W.
*/

#include <iostream>

int knapsack(int W, int wt[], int val[], int n) {
  if (n == 0 || W == 0) return 0;

  if (wt[n - 1] > W) return knapsack(W, wt, val, n - 1);

  return std::max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
                  knapsack(W, wt, val, n - 1));
}

int main() {
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int W = 50;
  int n = sizeof(val) / sizeof(val[0]);
  std::cout << knapsack(W, wt, val, n) << std::endl;
  return 0;
}
