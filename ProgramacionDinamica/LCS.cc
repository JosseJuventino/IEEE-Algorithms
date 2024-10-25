/*
    LCS (Longest Common Subsequence) encuentra la subsecuencia común más larga
    entre dos secuencias. Una subsecuencia es una secuencia que se puede obtener
    eliminando algunos elementos de otra secuencia. No es lo mismo que una
    subcadena, ya que no es necesario que los elementos estén contiguos.

    Una subsecuencia común es una subsecuencia que es común a ambas secuencias.
    es decir que se puede obtener eliminando algunos elementos de ambas
   secuencias.

    Por ejemplo, si tenemos las secuencias X
    X = "ABCBDAB" y Y = "BDCAB", la subsecuencia común más larga es "BCAB" de
    longitud 4. Ya que se puede obtener eliminando los elementos "A" y "D" de la
    secuencia X y los elementos "D" y "B" de la secuencia Y.

    La fórmula para calcular la longitud de la subsecuencia común más larga es
    la siguiente:

    dp[i][j] = dp[i - 1][j - 1] + 1 si X[i] == Y[j]
    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) si X[i] != Y[j]

    Donde:
        - dp[i][j] es la longitud de la subsecuencia común más larga entre los
        primeros i elementos de X y los primeros j elementos de Y.

        - X[i] es el i-ésimo elemento de la secuencia X.
        - Y[j] es el j-ésimo elemento de la secuencia Y.
*/

#include <iostream>
#include <vector>
using namespace std;

int LCS(string x, string y, int n, int m) {
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (x[i - 1] == y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[n][m];
}

int main() {
  string x = "ABCBDAB";
  string y = "BDCAB";
  int n = x.size();
  int m = y.size();
  cout << "La longitud de la LCS es: " << LCS(x, y, n, m) << endl;
  return 0;
}