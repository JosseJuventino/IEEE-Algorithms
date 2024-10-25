/*
    La distancia de edicion de Levenshtein es un algoritmo que permite calcular la
    distancia entre dos cadenas. La distancia de edicion es el número mínimo de
    operaciones necesarias para convertir una cadena en otra. Las operaciones permitidas
    son:
        1. Insertar un caracter.
        2. Eliminar un caracter.
        3. Reemplazar un caracter.
    
    El algoritmo de distancia de edicion de Levenshtein consiste en los siguientes pasos:
        1. Inicializa una matriz de tamaño (n + 1) x (m + 1) con 0 en la primera fila y
        en la primera columna.
        2. Recorre la matriz y calcula la distancia de edicion de las subcadenas.
        3. Si los caracteres de las subcadenas son iguales, el valor de la celda es el
        mismo que el de la celda diagonal superior izquierda.
        4. Si los caracteres de las subcadenas son diferentes, el valor de la celda es el
        mínimo de los valores de la celda diagonal superior izquierda, la celda superior y
        la celda izquierda más 1.
        5. El valor de la celda en la última fila y la última columna es la distancia de
        edicion entre las dos cadenas.
    
    Se usa este algoritmo para encontrar la distancia entre dos cadenas. Por ejemplo
    la distancia de edicion entre "kitten" y "sitting" es 3. Porque se necesitan 3
    operaciones para convertir "kitten" en "sitting":
        1. Reemplazar 'k' por 's'.
        2. Reemplazar 'e' por 'i'.
        3. Insertar 'g' al final.
*/

#include <iostream>

int stringLength(const char* str) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

int min(int a, int b, int c) {
  int m = a < b ? a : b;
  return m < c ? m : c;
}

int editDistance(char* str1, char* str2) {
  int m = stringLength(str1);
  int n = stringLength(str2);
  int dp[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0)
        dp[i][j] = j;
      else if (j == 0)
        dp[i][j] = i;
      else if (str1[i - 1] == str2[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
    }
  }
  return dp[m][n];
}

int main() {
  char str1[] = "kitten";
  char str2[] = "sitting";
  std::cout << "Edit distance is " << editDistance(str1, str2) << std::endl;
  return 0;
}
