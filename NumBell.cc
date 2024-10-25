/*
    Los números de Bell son una secuencia matemática en combinatoria que cuenta
    el número de maneras de particionar un conjunto de 𝑛 n elementos en
    subconjuntos no vacíos. En otras palabras, el n-ésimo número de Bell cuenta
    cuántas formas diferentes existen de dividir un conjunto de 𝑛 n elementos en
    grupos (subconjuntos no vacíos).

    Para n = 3, si tenemos el conjunto {1, 2, 3}, las particiones posibles son:
    {1}, {2}, {3}
    {1, 2}, {3}
    {1, 3}, {2}
    {2, 3}, {1}
    {1, 2, 3}

    La fórmula para calcular los números de Bell es la siguiente:
    B(n) = Σ_{k=0}^{n} S(n, k)

    Entonces el numero de Bell B3 = 5 ya que hay 5 formas de particionar un
   conjunto de 3 elementos.
*/

#include <iostream>
using namespace std;

unsigned long long binomial(int n, int k) {
  if (k > n) return 0;
  if (k == 0 || k == n) return 1;

  unsigned long long res = 1;
  for (int i = 1; i <= k; ++i) {
    res = res * (n - i + 1) / i;
  }
  return res;
}

unsigned long long bellNumber(int n) {
  unsigned long long bell[n + 1];

  bell[0] = 1;

  for (int i = 1; i <= n; i++) {
    bell[i] = 0;
    for (int j = 0; j < i; j++) {
      bell[i] += binomial(i - 1, j) * bell[j];
    }
  }

  return bell[n];
}
