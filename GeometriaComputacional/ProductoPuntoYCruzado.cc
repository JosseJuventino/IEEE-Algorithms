#include <iostream>

// Estructura para representar un punto en el plano
struct Punto {
    int x, y;
};

/*
    Producto Cruzado:
    El producto cruzado entre dos vectores nos da un valor que ayuda a determinar la orientación entre ellos.
    Para dos puntos p y q, y usando un punto de referencia r, podemos ver si el camino p -> r -> q
    es un giro a la izquierda, a la derecha, o si es colineal.
    Fórmula: (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x)
    Resultado:
      - Positivo: indica un giro a la izquierda (antihorario).
      - Negativo: indica un giro a la derecha (horario).
      - Cero: indica que los puntos son colineales.
*/
int productoCruzado(Punto p, Punto q, Punto r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

/*
    Producto Punto:
    El producto punto entre dos vectores nos da un valor que indica la relación angular entre ellos.
    Para dos puntos p y q, con un origen en el punto r:
    Fórmula: (q.x - p.x) * (r.x - p.x) + (q.y - p.y) * (r.y - p.y)
    Resultado:
      - Positivo: indica que el ángulo entre los vectores es agudo.
      - Negativo: indica que el ángulo entre los vectores es obtuso.
      - Cero: indica que los vectores son perpendiculares.
*/
int productoPunto(Punto p, Punto q, Punto r) {
    return (q.x - p.x) * (r.x - p.x) + (q.y - p.y) * (r.y - p.y);
}

// Función para verificar si tres puntos son colineales usando el producto cruzado
bool sonColineales(Punto p, Punto q, Punto r) {
    return productoCruzado(p, q, r) == 0;
}

// Función para calcular el área de un triángulo definido por tres puntos usando el producto cruzado
double areaTriangulo(Punto p, Punto q, Punto r) {
    return std::abs(productoCruzado(p, q, r)) / 2.0;
}

// Función principal para probar las operaciones
int main() {
    Punto p = {1, 2};
    Punto q = {3, 4};
    Punto r = {5, 6};

    // Verificar si los puntos son colineales
    if (sonColineales(p, q, r)) {
        std::cout << "Los puntos son colineales.\n";
    } else {
        std::cout << "Los puntos no son colineales.\n";
    }

    // Calcular y mostrar el área del triángulo formado por los tres puntos
    double area = areaTriangulo(p, q, r);
    std::cout << "El área del triángulo formado por los puntos es: " << area << "\n";

    // Calcular el producto punto y cruzado
    int cruzado = productoCruzado(p, q, r);
    int punto = productoPunto(p, q, r);

    std::cout << "Producto Cruzado entre p, q, r: " << cruzado << "\n";
    std::cout << "Producto Punto entre p, q, r: " << punto << "\n";

    return 0;
}
