/*
    Dijkstra es un algoritmo que permite encontrar el camino más corto 
    entre un nodo y todos los demás nodos de un grafo con pesos no negativos.

    El algoritmo de Dijkstra consiste en los siguientes pasos:
        1. Inicializa un arreglo de distancias con infinito y la distancia al nodo
        inicial como 0.
        2. Inserta el nodo inicial en una cola de prioridad.
        3. Mientras la cola de prioridad no esté vacía:
            1. Extrae el nodo con la menor distancia de la cola.
            2. Recorre todos los nodos adyacentes del nodo actual.
            3. Si la distancia al nodo adyacente es mayor que la distancia al nodo
            actual más el peso de la arista entre ambos nodos, actualiza la
            distancia al nodo adyacente y encola el nodo adyacente.
        4. Repite el paso 3 hasta que la cola de prioridad esté vacía.

*/

#include <iostream>
using namespace std;

const int N = 100;
const int INF = 1e9;

int grafo[N][N];
int dist[N]; // Distancia al nodo i
bool visitado[N];

int encontrarMinimo(int n) {
  int minDist = INF;
  int minIndex = -1;
  for (int i = 0; i < n; i++) {
    if (!visitado[i] && dist[i] < minDist) {
      minDist = dist[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void Dijkstra(int inicio, int n) {
  for (int i = 0; i < n; i++) {
    dist[i] = INF;
    visitado[i] = false;
  }
  dist[inicio] = 0;

  for (int i = 0; i < n; i++) {
    int u = encontrarMinimo(n);
    if (u == -1) break;
    visitado[u] = true;

    for (int v = 0; v < n; v++) {
      if (grafo[u][v] && !visitado[v] && dist[u] + grafo[u][v] < dist[v]) {
        dist[v] = dist[u] + grafo[u][v];
      }
    }
  }
}

int main() {
  int n = 5;
  grafo[0][1] = 10;
  grafo[1][2] = 20;
  grafo[2][3] = 30;
  grafo[3][4] = 40;
  Dijkstra(0, n);
  for (int i = 0; i < n; i++) {
    cout << "Distancia al nodo " << i << " es " << dist[i] << endl;
  }
  return 0;
}
