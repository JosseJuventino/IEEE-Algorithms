#include <iostream>
#include <string>
using namespace std;

string lookAndSay(const string& current) {
  string next = "";  // Para almacenar el siguiente término
  int count = 1;     // Contador de dígitos

  for (int i = 0; i < current.length(); i++) {
    // Comprobar si el siguiente dígito es el mismo
    if (i < current.length() - 1 && current[i] == current[i + 1]) {
      count++;  // Incrementar el contador si es igual
    } else {
      // Agregar el conteo y el dígito al siguiente término
      next += to_string(count) + current[i];
      count = 1;  // Reiniciar el contador
    }
  }

  return next;  // Retornar el siguiente término
}

int main() {
  int n;
  cout << "Introduce el número de términos a generar: ";
  cin >> n;

  string current = "1";     // Primer término
  cout << current << endl;  // Imprimir el primer término

  for (int i = 1; i < n; i++) {
    current = lookAndSay(current);  // Generar el siguiente término
    cout << current << endl;        // Imprimir el término generado
  }

  return 0;
}
