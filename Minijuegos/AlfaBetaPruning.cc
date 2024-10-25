/*
    El algoritmo de poda alfa-beta es una mejora del algoritmo minimax que
   reduce el número de nodos evaluados en el árbol de búsqueda. La poda
   alfa-beta elimina los nodos que no afectan el resultado final, es decir, los
   nodos que no influyen en la decisión final del jugador.

    La poda alfa-beta se basa en dos valores, alfa y beta, que representan los
    valores de los nodos en el árbol de búsqueda. Alfa representa el valor del
    nodo máximo encontrado hasta el momento, mientras que beta representa el
   valor del nodo mínimo encontrado hasta el momento.

    Se usa para ejercicios de backtracking, es decir para problemas en los que
    se deben probar todas las posibles soluciones.

*/

#include <iostream>

int alphaBeta(int depth, int nodeIndex, bool isMaximizingPlayer, int values[],
              int alpha, int beta, int h) {
  // Si hemos alcanzado la profundidad máxima, devolvemos el valor del nodo hoja
  if (depth == h) return values[nodeIndex];

  if (isMaximizingPlayer) {
    int best = -10000;  // Usamos un valor muy pequeño para iniciar la búsqueda
                        // del máximo

    // Recorrer los hijos del nodo actual
    for (int i = 0; i < 2; i++) {
      int val = alphaBeta(depth + 1, nodeIndex * 2 + i, false, values, alpha,
                          beta, h);
      best = std::max(best, val);
      alpha = std::max(alpha, best);

      // Si el valor de beta es menor o igual que alpha, se produce poda
      if (beta <= alpha) break;
    }
    return best;
  } else {
    int best = 10000;  // Usamos un valor muy grande para iniciar la búsqueda
                       // del mínimo

    // Recorrer los hijos del nodo actual
    for (int i = 0; i < 2; i++) {
      int val =
          alphaBeta(depth + 1, nodeIndex * 2 + i, true, values, alpha, beta, h);
      best = std::min(best, val);
      beta = std::min(beta, best);

      // Si el valor de beta es menor o igual que alpha, se produce poda
      if (beta <= alpha) break;
    }
    return best;
  }
}

// Función auxiliar para encontrar la altura del árbol
int log2(int n) {
  int r = 0;
  while (n > 1) {
    n /= 2;
    r++;
  }
  return r;
}

int main() {
  // Supongamos que tenemos un árbol de juego completo con valores en los nodos
  // hoja
  int values[] = {3, 5, 6, 9, 1, 2, 0, -1};
  int n = sizeof(values) / sizeof(values[0]);

  // Altura del árbol
  int h = log2(n);

  int alpha = -10000;  // Valor pequeño inicial para alpha
  int beta = 10000;    // Valor grande inicial para beta

  std::cout << "El valor óptimo es: "
            << alphaBeta(0, 0, true, values, alpha, beta, h) << std::endl;

  return 0;
}
