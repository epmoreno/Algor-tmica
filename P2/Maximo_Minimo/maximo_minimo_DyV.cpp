/**
 * @file maximo_minimo_DyV.cpp
 * @brief Programa para encontrar el máximo y mínimo de un vector utilizando la técnica de Divide y Vencerás.
 * @details Este programa utiliza OpenMP para paralelizar la búsqueda del máximo y mínimo en un vector de enteros.
 *          La eficiencia teórica en el peor de los casos es O(n log n), y en el mejor de los casos es O(n).
 *          El algoritmo divide el vector en dos mitades, encuentra el máximo y mínimo en cada mitad y combina los resultados.
 *          Se utiliza la directiva #pragma omp parallel sections para paralelizar la búsqueda en ambas mitades, y se combinan las soluciones para obtener el resultado final.
 *          El programa también incluye una estructura ResultadoMaxMin para almacenar los índices del máximo y mínimo encontrados.
 * @author Enrique Pinazo Moreno
 * @date 2025-04-15
 */


#include <iostream>
#include <omp.h>
using namespace std;

/**
 * @brief Structura para almacenar los índices del máximo y mínimo encontrados en un segmento del vector.
 * @param max_idx Índice del máximo encontrado.
 * @param min_idx Índice del mínimo encontrado.
 */
struct ResultadoMaxMin {
   int max_idx;
   int min_idx;
};

/**
 * @brief Función para encontrar el máximo y mínimo en un segmento del vector.
 * @param v Vector de enteros.
 * @param inicio Índice de inicio del segmento.
 * @param fin Índice de fin del segmento.
 * @return Los indices del valor maximo y minimo.
 */
ResultadoMaxMin encontrar_maximo_minimo_segmento(int *v, int inicio, int fin) {
    ResultadoMaxMin res;
    int min = v[0];
    int max = v[0];
    int idx_max = 0;
    int idx_min = 0;
    for(int i = inicio; i < fin; i++) {
        /// Aquí se busca el máximo en la mitad 
        if(v[i] > max) {
            max = v[i];
            idx_max = i;
        }
        /// Aquí se busca el mínimo en la mitad 
        if(v[i] < min) {
            min = v[i];
            idx_min = i;
        }
    }
    /// Almacenar los índices del máximo y mínimo encontrados
    res.max_idx = idx_max;
    res.min_idx = idx_min;
    return res;
}

/**
 * @brief Función recursiva para encontrar el máximo y mínimo en un vector utilizando OpenMP.
 * @param v Vector de enteros.
 * @param n Tamaño del vector.
 * @param max_idx Índice del máximo encontrado.
 * @param min_idx Índice del mínimo encontrado.
 * @details Se plantean los casos base para un elemento y dos elementos, para evitar la recursión innecesaria.
 */
void encontrar_maximo_minimo(int *v, int n, int &max_idx, int &min_idx) {
    if(n <= 1) {
        max_idx = 0;
        min_idx = 0;
        return;
    }

    if(n == 2) {            /// Caso base para dos elementos
        if(v[0] > v[1]) {
            max_idx = 0;
            min_idx = 1;
        } else {
            max_idx = 1;
            min_idx = 0;
        }
        return;
    }

    int medio = n/2;
    int max_idx_izq, min_idx_izq;
    int max_idx_der, min_idx_der;
    
    /// Dividir el vector en dos mitades y buscar el máximo y mínimo en paralelo

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            ResultadoMaxMin res_izq = encontrar_maximo_minimo_segmento(v, 0, medio);
            max_idx_izq = res_izq.max_idx;
            min_idx_izq = res_izq.min_idx;
        }

        #pragma omp section
        {   
            ResultadoMaxMin res_der = encontrar_maximo_minimo_segmento(v, medio, n);
            max_idx_der = res_der.max_idx;
            min_idx_der = res_der.min_idx;
        }
    }
    
    #pragma omp barrier

    /// Comparar los resultados de ambas mitades
    #pragma omp single
    {
        if(v[max_idx_izq] > v[max_idx_der]) {
            max_idx = max_idx_izq;
        } else {
            max_idx = max_idx_der;
        }
        if(v[min_idx_izq] < v[min_idx_der]) {
            min_idx = min_idx_izq;
        } else {
            min_idx = min_idx_der;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n = 7;                                       /// Tamaño del vector
    int *v = new int[n];
    v[0] = 5;  v[1] = 904; v[2] = 10;                /// Declaración de los elementos del vector/
    v[3] = 100; v[4] = 13; v[5] = 54; v[6] = 905;    /// ...
    
    int max_idx, min_idx;                            /// Variables para almacenar los índices del máximo y mínimo
    encontrar_maximo_minimo(v, n, max_idx, min_idx); /// Llamada a la función para encontrar el máximo y mínimo
    
    /// Mostrar el vector
    cout << "El vector es: [";
    for(int i = 0; i < n; i++) {
        cout << v[i];
        if(i < n-1) cout << ", ";
    }
    cout <<"]"<< endl;
    /// Mostrar los resultados
    cout << "El máximo es: " << v[max_idx] << " en la posición " << max_idx << endl;
    cout << "El mínimo es: " << v[min_idx] << " en la posición " << min_idx << endl;
    
    delete[] v; /// Liberar la memoria del vector dinámico

    return 0;
}