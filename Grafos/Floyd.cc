/*
    Floyd-Warshall es un algoritmo de programación dinámica que se utiliza para
    encontrar las distancias más cortas entre todos los pares de nodos en un grafo
    con pesos. El algoritmo de Floyd-Warshall funciona para grafos dirigidos y no
    dirigidos, y puede manejar grafos con pesos negativos, siempre y cuando no
    contengan ciclos negativos.

    El algoritmo de Floyd-Warshall consiste en los siguientes pasos:
        1. Inicializa una matriz de distancias con infinito y la distancia de un
        nodo a sí mismo como 0.
        2. Actualiza la matriz de distancias con los pesos de las aristas.
        3. Recorre todos los nodos y para cada par de nodos (i, j) verifica si la
        distancia de i a j es mayor que la distancia de i a k más la distancia de k
        a j, en cuyo caso actualiza la distancia de i a j.

    Se usa para ejercicios que requieran encontrar las distancias más cortas entre
    todos los pares de nodos en un grafo con pesos.
*/

#include <iostream>
using namespace std;

const int N = 100;
const int INF = 1e9;
int dist[N][N];

void floydWarshall(int n) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] != INF && dist[k][j] != INF) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
}

int main() {
  int n = 5;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = (i == j) ? 0 : INF;
    }
  }
  dist[0][1] = 3;
  dist[1][2] = 5;
  dist[2][3] = 7;
  dist[3][4] = 2;
  floydWarshall(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dist[i][j] == INF)
        cout << "INF ";
      else
        cout << dist[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
