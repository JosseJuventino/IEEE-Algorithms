/*
    El BFS o busqueda en anchura es un algoritmo que recorre o explora todos los
    nodos de un grafo o arbol de manera iterativa, nivel por nivel. El BFS se
    implementa utilizando una cola y se puede utilizar para encontrar la distancia
    más corta entre dos nodos en un grafo no ponderado.

    El algoritmo de BFS consiste en los siguientes pasos:
        1. Inserta el nodo inicial en la cola y marca el nodo como visitado.
        2. Mientras la cola no esté vacía:
            1. Extrae un nodo de la cola.
            2. Recorre todos los nodos adyacentes del nodo actual.
            3. Si un nodo adyacente no ha sido visitado, márcalo como visitado y
               agrégalo a la cola.
        3. Repite el paso 2 hasta que la cola esté vacía.

    Se usa este algoritmo para ejercicios que requieran recorrer un grafo o arbol
    de manera iterativa, nivel por nivel.
*/

#include <iostream>
using namespace std;

const int N = 100;  // Número máximo de nodos
int adj[N][N];      // Matriz de adyacencia
bool visitado[N];   // Nodos visitados
int cola[N];        // Implementación de cola
int inicio, fin;    // Punteros para manejar la cola

void inicializarCola() { inicio = fin = 0; }

void encolar(int valor) { cola[fin++] = valor; }

int desencolar() { return cola[inicio++]; }

bool estaVacia() { return inicio == fin; }

void BFS(int inicioNodo, int n) {
  encolar(inicioNodo);
  visitado[inicioNodo] = true;

  while (!estaVacia()) {
    int nodo = desencolar();
    cout << nodo << " ";  // Imprimir nodo visitado

    for (int i = 0; i < n; i++) {
      if (adj[nodo][i] && !visitado[i]) {
        encolar(i);
        visitado[i] = true;
      }
    }
  }
}

int main() {
  int n = 5;  // Número de nodos
  adj[0][1] = adj[1][2] = adj[2][3] = adj[3][4] = adj[4][0] = 1;
  inicializarCola();
  BFS(0, n);  // Inicia BFS desde el nodo 0
  return 0;
}
