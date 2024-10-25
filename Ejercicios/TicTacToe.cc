#include <iostream>
using namespace std;

int checkWinner(int board[3][3]) {
  // Verificar filas y columnas
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      if (board[i][0] == 1) return 1;  // Jugador X gana
      if (board[i][0] == 2) return 2;  // Jugador O gana
    }
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      if (board[0][i] == 1) return 1;  // Jugador X gana
      if (board[0][i] == 2) return 2;  // Jugador O gana
    }
  }
  // Verificar diagonales
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    if (board[0][0] == 1) return 1;  // Jugador X gana
    if (board[0][0] == 2) return 2;  // Jugador O gana
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    if (board[0][2] == 1) return 1;  // Jugador X gana
    if (board[0][2] == 2) return 2;  // Jugador O gana
  }
  return 0;  // Ningún ganador
}

bool isValid(int board[3][3]) {
  int countX = 0, countO = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 1)
        countX++;  // Contar X
      else if (board[i][j] == 2)
        countO++;  // Contar O
    }
  }

  // Reglas de validación
  if (countX < countO || countX > countO + 1)
    return false;  // X no puede tener más de un turno extra
  return true;
}

int main() {
  int board[3][3];

  // Leer el tablero
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> board[i][j];  // 0 = vacío, 1 = X, 2 = O
    }
  }

  // Validar el tablero
  if (!isValid(board)) {
    cout << -1 << endl;  // Estado no válido
    return 0;
  }

  // Comprobar el ganador
  int winner = checkWinner(board);
  if (winner != 0) {
    cout << winner << endl;  // Jugador 1 (X) o 2 (O) gana
    return 0;
  }

  // Comprobar si hay un empate
  bool isDraw = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 0) {
        isDraw = false;  // Hay un espacio vacío, no es empate
      }
    }
  }

  if (isDraw) {
    cout << 0 << endl;  // Empate
  } else {
    // Si no hay ganador y hay espacios vacíos, el juego continúa
    cout << 1 << endl;  // Se puede seguir jugando
  }

  return 0;
}
