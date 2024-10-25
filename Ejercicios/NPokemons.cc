/*
    El problema trata sobre la evolución de Pokémon, donde tienes:

    N Pokémon.
    M caramelos (o candy bars) disponibles.
    Para evolucionar un Pokémon, necesitas gastar X caramelos.
    Alternativamente, puedes vender un Pokémon (no evolucionado) por Y
caramelos.

    Tu objetivo es maximizar el número de Pokémon que puedes evolucionar.

    Solución:
    Dado que puedes vender Pokémon para obtener más caramelos, el enfoque será
    encontrar el número máximo de Pokémon que puedes evolucionar utilizando la
    cantidad de caramelos actuales y los caramelos que puedes ganar vendiendo
    algunos de tus Pokémon.

    El problema puede dividirse en los siguientes pasos:

    Inicialmente, intenta evolucionar el máximo número de Pokémon que puedas con los
    caramelos que tienes. Si te quedas sin caramelos, vende Pokémon para ganar más
    caramelos y poder evolucionar más. El objetivo final es maximizar el número de
    evoluciones posibles.
*/

#include <iostream>

using namespace std;

int maxEvolutions(int N, int M, int X, int Y) {
  int evolutions = 0;

  // Mientras haya Pokémon disponibles
  while (N > 0) {
    // Si tienes suficientes caramelos para evolucionar un Pokémon
    if (M >= X) {
      int evolvable = min(N, M / X);  // Calcula cuántos puedes evolucionar
      evolutions += evolvable;        // Aumenta el número de evoluciones
      M -= evolvable * X;             // Resta los caramelos utilizados
      N -= evolvable;                 // Resta los Pokémon evolucionados
    }
    // Si no tienes suficientes caramelos, vende un Pokémon
    else {
      // Solo puedes vender si el precio Y de vender un Pokémon es mayor que 0
      if (Y == 0 || N == 0)
        break;  // Si no puedes ganar caramelos adicionales, sal del bucle
      M += Y;   // Ganas Y caramelos por vender un Pokémon
      N--;      // Reducimos el número de Pokémon disponibles
    }
  }

  return evolutions;
}

int main() {
  int N, M, X, Y; 
  //N es el número de pokemones, M es la cantidad de caramelos, 
  //X es la cantidad de caramelos para evolucionar, 
  //Y es la cantidad de caramelos por vender un pokemon
  cin >> N >> M >> X >> Y;

  cout << maxEvolutions(N, M, X, Y) << endl;

  return 0;
}
