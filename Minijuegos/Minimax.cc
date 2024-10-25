#include <iostream>

#define JUGADOR 1    // Representa al jugador que maximiza
#define OPONENTE -1  // Representa al jugador que minimiza
#define VACIO 0      // Representa una celda vacía

const int FILAS = 3;
const int COLUMNAS = 3;

// Valores extremos para el algoritmo Minimax (en lugar de INT_MIN y INT_MAX)
const int EVALUACION_MAXIMA = 1000;
const int EVALUACION_MINIMA = -1000;

// Función para mostrar el tablero
void mostrarTablero(int tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == JUGADOR) std::cout << "X ";
            else if (tablero[i][j] == OPONENTE) std::cout << "O ";
            else std::cout << ". ";
        }
        std::cout << "\n";
    }
}

// Función para verificar si un jugador ha ganado
int evaluar(int tablero[FILAS][COLUMNAS]) {
    // Revisar filas y columnas
    for (int i = 0; i < FILAS; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            if (tablero[i][0] != VACIO) return tablero[i][0];
        }
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            if (tablero[0][i] != VACIO) return tablero[0][i];
        }
    }

    // Revisar diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        if (tablero[0][0] != VACIO) return tablero[0][0];
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        if (tablero[0][2] != VACIO) return tablero[0][2];
    }

    // Sin ganador
    return 0;
}

// Función para verificar si hay movimientos disponibles
bool hayMovimientos(int tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == VACIO) return true;
        }
    }
    return false;
}

// Función Minimax con poda Alfa-Beta
int minimax(int tablero[FILAS][COLUMNAS], int profundidad, bool esMax, int alfa, int beta) {
    int puntaje = evaluar(tablero);

    // Si el jugador gana
    if (puntaje == JUGADOR) return puntaje - profundidad;

    // Si el oponente gana
    if (puntaje == OPONENTE) return puntaje + profundidad;

    // Si no hay más movimientos
    if (!hayMovimientos(tablero)) return 0;

    // Si es el turno del jugador (maximiza)
    if (esMax) {
        int mejor = EVALUACION_MINIMA;
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                if (tablero[i][j] == VACIO) {
                    tablero[i][j] = JUGADOR;  // Realiza la jugada
                    mejor = std::max(mejor, minimax(tablero, profundidad + 1, false, alfa, beta));
                    tablero[i][j] = VACIO;    // Deshace la jugada
                    alfa = std::max(alfa, mejor);

                    // Poda Alfa-Beta
                    if (beta <= alfa) return mejor;
                }
            }
        }
        return mejor;
    }
    // Si es el turno del oponente (minimiza)
    else {
        int mejor = EVALUACION_MAXIMA;
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                if (tablero[i][j] == VACIO) {
                    tablero[i][j] = OPONENTE; // Realiza la jugada
                    mejor = std::min(mejor, minimax(tablero, profundidad + 1, true, alfa, beta));
                    tablero[i][j] = VACIO;    // Deshace la jugada
                    beta = std::min(beta, mejor);

                    // Poda Alfa-Beta
                    if (beta <= alfa) return mejor;
                }
            }
        }
        return mejor;
    }
}

// Función para encontrar la mejor jugada
std::pair<int, int> mejorJugada(int tablero[FILAS][COLUMNAS]) {
    int mejorValor = EVALUACION_MINIMA;
    std::pair<int, int> mejorMovimiento = {-1, -1};

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == VACIO) {
                tablero[i][j] = JUGADOR;
                int valorMovimiento = minimax(tablero, 0, false, EVALUACION_MINIMA, EVALUACION_MAXIMA);
                tablero[i][j] = VACIO;

                if (valorMovimiento > mejorValor) {
                    mejorMovimiento = {i, j};
                    mejorValor = valorMovimiento;
                }
            }
        }
    }
    return mejorMovimiento;
}

// Función principal
int main() {
    int tablero[FILAS][COLUMNAS] = {
        { JUGADOR, OPONENTE, VACIO },
        { VACIO, JUGADOR, OPONENTE },
        { VACIO, VACIO, VACIO }
    };

    std::cout << "Tablero inicial:\n";
    mostrarTablero(tablero);

    // Encontrar la mejor jugada para el jugador
    std::pair<int, int> movimiento = mejorJugada(tablero);
    std::cout << "La mejor jugada para el jugador es: (" << movimiento.first << ", " << movimiento.second << ")\n";

    return 0;
}
