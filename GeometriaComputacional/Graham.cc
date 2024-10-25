#include <iostream>
#define MAX_POINTS 100

// Estructura para representar un punto en el plano
struct Punto {
    int x, y;
};

/*
    Algoritmo de Graham:
    El Algoritmo de Graham es una técnica para encontrar el "convex hull" o envoltura convexa
    de un conjunto de puntos en el plano. La envoltura convexa es el contorno mínimo que contiene
    todos los puntos del conjunto, como si envolviéramos los puntos en una banda elástica y la soltáramos.

    Este algoritmo funciona en tres pasos principales:
    1. Encuentra el punto más bajo en el eje y (o el punto más bajo en el eje x si hay empate).
       Este punto se selecciona como el punto de referencia, llamado `p0`.
    2. Ordena todos los puntos restantes en función del ángulo polar que forman respecto a `p0`.
       Esto organiza los puntos en un "camino" que sigue el contorno exterior de los puntos.
    3. Usa una pila para construir el convex hull, agregando puntos y retrocediendo cuando se
       forma un giro a la derecha, lo cual indica que los puntos no están en el borde exterior.
*/

int orientacion(Punto p, Punto q, Punto r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Colineal
    return (val > 0) ? 1 : 2; // 1 -> Derecha, 2 -> Izquierda
}

// Función para intercambiar dos puntos, usada en la ordenación
void intercambiar(Punto &p1, Punto &p2) {
    Punto temp = p1;
    p1 = p2;
    p2 = temp;
}

// Calcula la distancia al cuadrado entre dos puntos (para evitar usar sqrt)
int distanciaCuadrada(Punto p1, Punto p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

// Ordena los puntos en base al ángulo polar respecto a un punto base p0
bool comparar(const Punto &p1, const Punto &p2, Punto p0) {
    int orient = orientacion(p0, p1, p2);
    if (orient == 0)
        return distanciaCuadrada(p0, p1) < distanciaCuadrada(p0, p2);
    return (orient == 2); // 2 -> Izquierda (ángulo más pequeño respecto a p0)
}

// Función de ordenación personalizada para el ángulo polar respecto a p0
void ordenarPuntos(Punto puntos[], int n, Punto p0) {
    // Ordenación de burbuja según el ángulo con p0
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!comparar(puntos[i], puntos[j], p0)) {
                intercambiar(puntos[i], puntos[j]);
            }
        }
    }
}

// Función para construir el convex hull usando el Algoritmo de Graham
void convexHull(Punto puntos[], int n, Punto hull[], int &hullSize) {
    // Paso 1: Encontrar el punto más bajo para usar como punto de referencia (p0)
    int minY = puntos[0].y, minIdx = 0;
    for (int i = 1; i < n; i++) {
        if ((puntos[i].y < minY) || (minY == puntos[i].y && puntos[i].x < puntos[minIdx].x)) {
            minY = puntos[i].y;
            minIdx = i;
        }
    }
    // Colocar el punto más bajo en la primera posición
    intercambiar(puntos[0], puntos[minIdx]);
    Punto p0 = puntos[0]; // Punto de referencia para ordenar

    // Paso 2: Ordenar los puntos en base al ángulo polar respecto a p0
    ordenarPuntos(puntos, n, p0);

    // Paso 3: Construir el convex hull usando una estructura similar a una pila
    hull[0] = puntos[0];
    hull[1] = puntos[1];
    hull[2] = puntos[2];
    hullSize = 3; // Empezamos con los primeros tres puntos en el hull

    // Revisar cada punto y decidir si es parte del hull
    for (int i = 3; i < n; i++) {
        // Mientras el último giro formado no sea a la izquierda, removemos el último punto
        while (hullSize > 1 && orientacion(hull[hullSize - 2], hull[hullSize - 1], puntos[i]) != 2) {
            hullSize--; // Retiramos puntos que no están en el convex hull
        }
        // Añadir el punto actual al hull
        hull[hullSize++] = puntos[i];
    }
}

// Función principal
int main() {
    Punto puntos[MAX_POINTS];
    int n;

    // Entrada de número de puntos y sus coordenadas
    std::cout << "Ingresa el número de puntos: ";
    std::cin >> n;

    // Validación de la cantidad mínima de puntos para formar un convex hull
    if (n < 3) {
        std::cout << "Se necesitan al menos 3 puntos para formar un convex hull.\n";
        return 0;
    }

    // Leer los puntos
    std::cout << "Ingresa las coordenadas de los puntos (x y): \n";
    for (int i = 0; i < n; i++) {
        std::cin >> puntos[i].x >> puntos[i].y;
    }

    // Array para almacenar el convex hull y su tamaño
    Punto hull[MAX_POINTS];
    int hullSize = 0;
    convexHull(puntos, n, hull, hullSize);

    // Imprimir los puntos que forman el convex hull
    std::cout << "Puntos en el convex hull:\n";
    for (int i = 0; i < hullSize; i++) {
        std::cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
    }

    return 0;
}
