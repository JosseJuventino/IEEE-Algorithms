#include <iostream>
using namespace std;

// Función para calcular la suma de divisores impares de un número
int sumaDivisoresImpares(int n) {
  int suma = 0;
  for (int i = 1; i <= n; i += 2) {  // Solo considerar números impares
    if (n % i == 0) {                // Si i es divisor de n
      suma += i;                     // Agregar a la suma
    }
  }
  return suma;  // Retornar la suma total
}

int main() {
  int T;     // Número de casos de prueba
  cin >> T;  // Leer el número de casos de prueba

  while (T--) {
    long long A, B;  // Usar long long para manejar el rango grande
    cin >> A >> B;   // Leer A y B

    long long sumaTotal = 0;                 // Inicializar la suma total
    for (long long i = A; i <= B; i++) {     // Iterar desde A hasta B
      sumaTotal += sumaDivisoresImpares(i);  // Sumar divisores impares
    }

    cout << sumaTotal << endl;  // Imprimir la suma total para el caso
  }

  return 0;
}
