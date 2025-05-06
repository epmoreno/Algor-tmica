/**
 * @file maximo_minimo_Scl.cpp
 * @brief Programa para encontrar el máximo y mínimo de un vector utilizando un algoritmo secuencial.
 * @details Este programa utiliza un algoritmo secuencial para encontrar el máximo y mínimo de un vector de enteros.
 *          La eficiencia teórica en el peor de los casos es O(n), y en el mejor de los casos es O(n).
 *          El algoritmo recorre el vector una sola vez, comparando cada elemento con el máximo y mínimo encontrados hasta el momento.
 *          Se utiliza un bucle for para recorrer el vector y encontrar el máximo y mínimo.
 *          El programa también incluye una función para imprimir el vector y los resultados.
 * @author Enrique Pinazo Moreno
 * @date 2025-04-15
 */
#include <iostream>

using namespace std;

/**
 * @brief Función para encontrar el máximo y mínimo en un vector.
 * @param v Vector de enteros.
 * @param n Tamaño del vector.
 * @param maxIdx Índice del máximo encontrado.
 * @param minIdx Índice del mínimo encontrado.
 * @param maX Valor máximo encontrado.
 * @param miN Valor mínimo encontrado.
 * @details Se plantean los casos base para un elemento y dos elementos, para evitar la recursión innecesaria.
 *          Se utiliza un bucle para recorrer el vector y encontrar el máximo y mínimo.
 */
void encontrar_maximo_minimo(int v[], int n, int &maxIdx, int &minIdx, int &maX, int &miN){
    /// Caso base para un y dos elementos
    if(n == 1){
        maxIdx = 0;
        minIdx = 0;
        maX = v[0];
        miN = v[0];
    }else if (n == 2){
        if (v[0] > v[1]){
            maxIdx = 0;
            minIdx = 1;
            maX = v[0];
            miN = v[1];
        }else{
            maxIdx = 1;
            minIdx = 0;
            maX = v[1];
            miN = v[0];
        }
    }
    /// Caso genearl n mayor a 2
    else{
        /// Se inicializa los maximo y minimo e indices respectivos en la primera posicion
        maX = v[0];
        miN = v[0];
        maxIdx = 0;
        minIdx = 0;

        for(int i = 1; i < n; i++){ /// Se recorre el vector empezando desde la segunda posicion
            /// Se encuentra el maximo
            if(v[i]>maX){
                maX = v[i];
                maxIdx = i;
            }
            /// Se encuentra el minimo
            if(v[i]<miN){
                miN = v[i];
                minIdx = i;
            }
        }
    }
};


int main(int argc, char const *argv[])
{
    int n = 7;
    int v[] = {5,904,10,100,13,54,905}; /// Declaración de los elementos del vector        
    int idx_max, idx_min, max, min;

    encontrar_maximo_minimo(v, n, idx_max, idx_min, max, min); /// Llamada a la función para encontrar el máximo y mínimo

    cout << "Vector: [";
    for(int i = 0; i < n; i++){
        cout << v[i];
        if(i < n-1){cout << ", ";}
    }
    cout << "]" << endl;
    cout << "El maximo es: (" << max << ") en la posicion: [" << idx_max <<"]"<< endl;
    cout << "El minimo es: (" << min << ") en la posicion: [" << idx_min <<"]"<< endl;
    return 0;
}
