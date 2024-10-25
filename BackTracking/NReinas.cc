/*
    El problema de las N-reinas consiste en colocar N reinas en un tablero de
   ajedrez de N x N de manera que ninguna reina pueda atacar a otra (es decir,
   no pueden estar en la misma fila, columna o diagonal).

    En este caso, se implementa una solución recursiva que coloca una reina en
    cada fila del tablero, verificando que no haya conflictos con las reinas
    ya colocadas. Si se llega a una solución, se imprime el tablero con las
    posiciones de las reinas.

    Complejidad: O(N!)

    Sirve para ejercicios de backtracking, es decir para problemas en los que
    se deben probar todas las posibles soluciones.
*/

#include <iostream>

#define N 8

void printSolution(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << board[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

bool isSafe(int board[N][N], int row, int col) {
  for (int i = 0; i < col; i++)
    if (board[row][i]) return false;

  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j]) return false;

  for (int i = row, j = col; i < N && j >= 0; i++, j--)
    if (board[i][j]) return false;

  return true;
}

bool solveNQueensUtil(int board[N][N], int col) {
  if (col >= N) return true;

  for (int i = 0; i < N; i++) {
    if (isSafe(board, i, col)) {
      board[i][col] = 1;

      if (solveNQueensUtil(board, col + 1)) return true;

      board[i][col] = 0;  // backtracking
    }
  }

  return false;
}

bool solveNQueens() {
  int board[N][N] = {0};

  if (!solveNQueensUtil(board, 0)) {
    std::cout << "Solution does not exist" << std::endl;
    return false;
  }

  printSolution(board);
  return true;
}

int main() {
  solveNQueens();
  return 0;
}
