/*
    Subset Sum Problem

    Dado un conjunto de enteros positivos y un valor sum, determinar si hay un
    subconjunto no vacío cuya suma sea igual a sum.

    Por ejemplo, si tenemos el conjunto {3, 34, 4, 12, 5, 2} y sum = 9, el
    subconjunto {4, 5} tiene una suma de 9.

    La solución al problema de la suma de subconjuntos se puede resolver
   mediante programación dinámica. La idea es crear una matriz dp de tamaño (n +
   1) x (sum
    + 1), donde n es el número de elementos en el conjunto y sum es la suma
    objetivo.

    La matriz dp[i][j] almacena si es posible obtener una suma j utilizando los
    primeros i elementos del conjunto. La matriz se llena de la siguiente
   manera: dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]]

    Donde:
        - dp[i][j] es verdadero si es posible obtener una suma j utilizando los
        primeros i elementos del conjunto.
        - dp[i - 1][j] es verdadero si es posible obtener una suma j sin incluir
        el i-ésimo elemento.
        - dp[i - 1][j - set[i - 1]] es verdadero si es posible obtener una suma
        j incluyendo el i-ésimo elemento.
*/

#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& nums, int target) {
  int n = nums.size();
  vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

  for (int i = 0; i <= n; ++i) {
    dp[i][0] = true;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= target; ++j) {
      if (nums[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[n][target];
}

int main() {
  vector<int> nums = {3, 34, 4, 12, 5, 2};
  int target = 9;  // Subconjunto con suma 9
  if (subsetSum(nums, target)) {
    cout << "Hay un subconjunto con la suma dada." << endl;
  } else {
    cout << "No existe un subconjunto con la suma dada." << endl;
  }
  return 0;
}
