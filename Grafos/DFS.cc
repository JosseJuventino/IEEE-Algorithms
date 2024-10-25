/*
    DFS (Depth First Search) es un algoritmo de búsqueda que recorre o explora
   todos los nodos de un grafo o árbol de manera recursiva. El DFS se puede
   utilizar para encontrar ciclos en un grafo, componentes conectados, árboles
   de expansión mínima, entre otros.

    El algoritmo de DFS consiste en los siguientes pasos:
        1. Marca el nodo actual como visitado.
        2. Recorre todos los nodos adyacentes del nodo actual.
        3. Si un nodo adyacente no ha sido visitado, llama a la función DFS con
   el nodo adyacente como parámetro.

    Se usa este algoritmo para ejercicios que requieran recorrer un grafo o
   árbol de manera recursiva.

    La diferencia entre BFS y DFS es que BFS recorre los nodos de un grafo o
   árbol de manera iterativa, nivel por nivel, mientras que DFS recorre los
   nodos de manera recursiva.
*/

#include <iostream>
using namespace std;

const int N = 100;
int adj[N][N];
bool visitado[N];

void DFS(int nodo, int n) {
  visitado[nodo] = true;
  cout << nodo << " ";

  for (int i = 0; i < n; i++) {
    if (adj[nodo][i] && !visitado[i]) {
      DFS(i, n);
    }
  }
}

int main() {
  int n = 5;
  adj[0][1] = adj[1][2] = adj[2][3] = adj[3][4] = adj[4][0] = 1;
  DFS(0, n);  // Inicia DFS desde el nodo 0
  return 0;
}
