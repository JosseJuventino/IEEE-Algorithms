/*
    Manacher Algorithm es un algoritmo que permite encontrar la subcadena
    palíndroma más larga en una cadena de texto. La idea principal es utilizar un 
    arreglo auxiliar para almacenar los palíndromos de cada posición de la cadena. 
    El algoritmo se basa en la simetría de los palíndromos, lo que permite evitar 
    recalcular los palíndromos de las posiciones ya visitadas.

    Por ejemplo 

    En la cadena "babad", la subcadena palíndroma más larga es "aba" o "bab".

*/

#include <iostream>

// Función para calcular la longitud de una cadena
int stringLength(const char* s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

// Función para transformar la cadena original agregando caracteres especiales
void preprocess(const char* s, char* t) {
    int n = stringLength(s);
    int j = 0;

    t[j++] = '^';  // Delimitador al inicio para evitar problemas con los límites

    for (int i = 0; i < n; i++) {
        t[j++] = '#';  // Añadir # antes de cada carácter
        t[j++] = s[i]; // Añadir el carácter original
    }

    t[j++] = '#';  // Añadir # después del último carácter
    t[j++] = '$';  // Delimitador final
    t[j] = '\0';   // Terminador nulo para la cadena transformada
}

// Función para encontrar el palíndromo más largo usando el algoritmo de Manacher
void longestPalindrome(const char* s) {
    int n = stringLength(s);
    if (n == 0) {
        std::cout << "No hay palíndromo." << std::endl;
        return;
    }

    // Cadena transformada
    char t[2 * n + 3]; // Transformación será aproximadamente 2 veces el tamaño de s + delimitadores
    preprocess(s, t);

    int tLength = 2 * n + 3;  // Longitud de la cadena transformada

    // Arreglo P donde P[i] almacenará el radio del palíndromo centrado en t[i]
    int P[tLength];
    for (int i = 0; i < tLength; i++) {
        P[i] = 0;
    }

    int C = 0, R = 0;  // Centro y radio del palíndromo más grande encontrado hasta ahora

    for (int i = 1; i < tLength - 1; i++) {
        int mirror = 2 * C - i;  // Posición espejo de i con respecto al centro C

        if (i < R) {
            P[i] = std::min(R - i, P[mirror]);  // Limitamos el valor inicial de P[i]
        }

        // Intentamos expandir el palíndromo centrado en i
        while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) {
            P[i]++;
        }

        // Si hemos expandido más allá de R, ajustamos C y R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Encontrar el palíndromo más largo
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < tLength - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Determinar el inicio del palíndromo en la cadena original
    int start = (centerIndex - maxLen) / 2;
    
    std::cout << "Palíndromo más largo: ";
    for (int i = start; i < start + maxLen; i++) {
        std::cout << s[i];
    }
    std::cout << std::endl;
}

int main() {
    char s[100];  // Arreglo de caracteres para la entrada
    std::cout << "Introduce la cadena: ";
    std::cin >> s;

    longestPalindrome(s);  // Llamamos a la función que encuentra el palíndromo más largo

    return 0;
}
