#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <limits> // Necesario para std::numeric_limits

using namespace std;

/**
 * @brief Calcula el coste mínimo de un camino que empieza en el centro de la primera columna
 * y se mueve hacia arriba, abajo y a la derecha.
 *
 * @param m La matriz de costes.
 * @return El coste mínimo para llegar a la última columna.
 */
int calcularCosteMinimoModificado(const std::vector<std::vector<int>>& m) {
    int f = m.size();
    if (f == 0) return 0;
    int c = m[0].size();
    if (c == 0) return 0;

    // 1. Estructura de datos: Crear la tabla de coste_minimo e inicializarla a infinito.
    const int INFINITO = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> coste_minimo(f, std::vector<int>(c, INFINITO));

    // 2. Casos Base: Primera columna
    // El camino empieza en la celda central de la primera columna.
    int fila_inicial = f / 2;
    coste_minimo[fila_inicial][0] = m[fila_inicial][0];

    // Propagar costes hacia abajo en la primera columna
    for (int i = fila_inicial + 1; i < f; ++i) {
        coste_minimo[i][0] = coste_minimo[i - 1][0] + m[i][0];
    }
    // Propagar costes hacia arriba en la primera columna
    for (int i = fila_inicial - 1; i >= 0; --i) {
        coste_minimo[i][0] = coste_minimo[i + 1][0] + m[i][0];
    }

    // 3. Relación de Recurrencia: Llenar el resto de la tabla
    for (int j = 1; j < c; ++j) {
        // Primero, calculamos el coste llegando desde la izquierda
        for (int i = 0; i < f; ++i) {
            if (coste_minimo[i][j - 1] != INFINITO) {
                coste_minimo[i][j] = m[i][j] + coste_minimo[i][j - 1];
            }
        }

        // Ahora, propagamos los costes verticalmente dentro de la columna j
        // Se hacen 'f' pasadas para garantizar la convergencia del coste mínimo en la columna.
        for (int k = 0; k < f; ++k) {
            // Pasada hacia abajo
            for (int i = 1; i < f; ++i) {
                 if (coste_minimo[i - 1][j] != INFINITO) {
                    coste_minimo[i][j] = std::min(coste_minimo[i][j], coste_minimo[i - 1][j] + m[i][j]);
                 }
            }
            // Pasada hacia arriba
            for (int i = f - 2; i >= 0; --i) {
                if (coste_minimo[i + 1][j] != INFINITO) {
                    coste_minimo[i][j] = std::min(coste_minimo[i][j], coste_minimo[i + 1][j] + m[i][j]);
                }
            }
        }
    }

    // 4. Resultado Final: El resultado es el mínimo de la última columna.
    int coste_final_minimo = coste_minimo[0][c - 1];
    for (int i = 1; i < f; ++i) {
        if (coste_minimo[i][c - 1] < coste_final_minimo) {
            coste_final_minimo = coste_minimo[i][c - 1];
        }
    }

    return coste_final_minimo;
}


int main(int argc, char const* argv[]) {
    if (argc < 4) {
        cout << "Error: No se han introducido suficientes argumentos." << endl;
        cout << "Uso: " << argv[0] << " <filas> <columnas> [elementos...]" << endl;
        return 1;
    }

    int f = atoi(argv[1]);
    int c = atoi(argv[2]);

    if (argc < 3 + f * c) {
        cout << "Error: Faltan elementos para llenar la matriz de " << f << "x" << c << "." << endl;
        cout << "Se necesitan " << f * c << " elementos." << endl;
        return 1;
    }

    vector<vector<int>> m(f, vector<int>(c));
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = atoi(argv[3 + i * c + j]);
        }
    }

    // Medición del tiempo de ejecución
    auto start = std::chrono::high_resolution_clock::now();

    int costeMinimo = calcularCosteMinimoModificado(m); // Llamada a la nueva función

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = end - start;

    std::cout << "El camino de suma mínima óptimo es: " << costeMinimo << std::endl;
    std::cout << "Tiempo de ejecución del algoritmo: " << duracion.count() << " segundos." << std::endl;

    return 0;
}