/*
    El algoritmo de kruskal es un algoritmo de la teoría de grafos que permite
    encontrar el árbol de expansión mínima de un grafo conexo y no dirigido. Un
    árbol de expansión mínima es un subgrafo que contiene todos los vértices del
    grafo original y es un árbol, es decir, no contiene ciclos.

    El algoritmo de kruskal consiste en los siguientes pasos:
        1. Ordena todas las aristas del grafo en orden no decreciente de acuerdo a
        sus pesos.
        2. Inicializa un conjunto de vértices disjuntos, es decir, cada vértice
        pertenece a un conjunto diferente.
        3. Recorre todas las aristas ordenadas y para cada arista (u, v) verifica si
        los vértices u y v pertenecen al mismo conjunto. Si no pertenecen al mismo
        conjunto, une los conjuntos de u y v y agrega la arista (u, v) al árbol de
        expansión mínima.
        4. Repite el paso 3 hasta que se hayan agregado n - 1 aristas al árbol de
        expansión mínima, donde n es el número de vértices del grafo.
    
    Se usa este algoritmo para encontrar el árbol de expansión mínima de un grafo
    conexo y no dirigido.
*/

#include <algorithm>
#include <iostream>
using namespace std;

const int N = 100;
int padre[N];

struct Arista {
  int u, v, peso;
};

Arista aristas[N * N];
int numAristas;

int encontrar(int u) {
  if (padre[u] != u) padre[u] = encontrar(padre[u]);
  return padre[u];
}

void unir(int u, int v) { padre[encontrar(u)] = encontrar(v); }

bool comparar(Arista a, Arista b) { return a.peso < b.peso; }

void ordenarAristas() {
  for (int i = 0; i < numAristas - 1; i++) {
    for (int j = i + 1; j < numAristas; j++) {
      if (comparar(aristas[j], aristas[i])) {
        Arista temp = aristas[i];
        aristas[i] = aristas[j];
        aristas[j] = temp;
      }
    }
  }
}

void kruskal(int n) {
  for (int i = 0; i < n; i++) padre[i] = i;
  ordenarAristas();

  int pesoTotal = 0;
  for (int i = 0; i < numAristas; i++) {
    int u = aristas[i].u, v = aristas[i].v, peso = aristas[i].peso;
    if (encontrar(u) != encontrar(v)) {
      unir(u, v);
      pesoTotal += peso;
      cout << "Arista seleccionada: (" << u << ", " << v << ") con peso "
           << peso << endl;
    }
  }
  cout << "Peso total del árbol de expansión mínima: " << pesoTotal << endl;
}

int main() {
  int n = 4;
  numAristas = 5;
  aristas[0] = {0, 1, 10};
  aristas[1] = {0, 2, 6};
  aristas[2] = {0, 3, 5};
  aristas[3] = {1, 3, 15};
  aristas[4] = {2, 3, 4};
  kruskal(n);
  return 0;
}
