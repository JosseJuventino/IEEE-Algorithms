/*
    You should implement a function that takes as argument a string S
    consisting only of parentheses. Return the size of the longest substring
which is correctly parenthesised. If there is no solution return −1

    Recorrido de la cadena:
    Si encontramos '(', almacenamos su índice en la pila.
    Si encontramos ')', intentamos emparejarlo con el último '(' almacenado (sacamos
    un elemento de la pila). Si la pila queda vacía, significa que hemos encontrado
    un paréntesis de cierre sin apertura correspondiente, así que almacenamos su
    índice como referencia. Si la pila no está vacía después de sacar un elemento,
    calculamos la longitud de la subcadena correctamente parentizada.
*/

#include <iostream>

int longestParenthesizedSubstring(const char* s) {
  int n = 0;
  while (s[n] != '\0') n++;  // Calculamos la longitud de la cadena manualmente

  int stack[n];  // Pila manual con un arreglo
  int top = -1;  // Índice que representa la "cima" de la pila
  int maxLength = 0;

  // Inicializamos la pila con un valor ficticio
  stack[++top] = -1;

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      // Guardamos el índice de los paréntesis de apertura
      stack[++top] = i;
    } else {
      // Si encontramos un paréntesis de cierre, retiramos un elemento de la
      // pila
      top--;

      if (top == -1) {
        // Si la pila está vacía, almacenamos el índice del paréntesis de cierre
        stack[++top] = i;
      } else {
        // Si hay elementos en la pila, calculamos la longitud de la subcadena
        // válida
        int length = i - stack[top];
        if (length > maxLength) {
          maxLength = length;
        }
      }
    }
  }

  return maxLength > 0
             ? maxLength
             : -1;  // Si no encontramos ninguna subcadena válida, devolvemos -1
}

int main() {
  char s[1000];  // Declaramos un arreglo suficientemente grande para la cadena
  std::cin >> s;

  int result = longestParenthesizedSubstring(s);
  std::cout << result << std::endl;

  return 0;
}
