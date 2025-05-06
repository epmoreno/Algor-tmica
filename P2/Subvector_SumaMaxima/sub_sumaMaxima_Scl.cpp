/**
 * @file sub_sumaMaxima_Scl.cpp
 * @brief Algoritmo para encontrar el subvector con la suma máxima de forma secuencial básica.
 * @details Este algoritmo utiliza un enfoque secuencial para encontrar el subvector con la suma máxima en un vector de enteros.
 *          La eficiencia teórica en el peor de los casos es O(n^2), y en el mejor de los casos es O(n).
 * @author Enrique Pinazo Moreno
 * @date 2025-04-15
 */

#include <iostream>

using namespace std;

/**
 * @brief Función para encontrar el subvector con la suma máxima
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @param vSMax Vector donde se guardará la suma máxima
 * @details Este algoritmo utiliza un enfoque secuencial para encontrar el subvector con la suma máxima.
 *          Se inicializa la suma máxima y se recorre el vector para encontrar la suma máxima.
 *          Se utiliza un bucle for para recorrer el vector y encontrar la suma máxima.
 *          La eficiencia teórica en el peor de los casos es O(n^2), y en el mejor de los casos es O(n).
 *          Se utiliza un bucle for para recorrer el vector y encontrar la suma máxima.
 */
void subSumaMaxima(int *v, int n, int *&vSMax){
    int maxActual = v[0];
    int maxGlobal = v[0];

    int inicio = 0;
    int fin = 0;
    int inicioMax = 0;
    int finMax = 0;
    for(int i = 1; i < n; i++){
        /// Si la suma actual más el nuevo elemento es menor que el nuevo elemento,
        /// comenzamos un nuevo subvector desde esta posición
        if(maxActual + v[i] <= v[i]){
            maxActual = v[i];
            inicio = i;
        }
        else{
            maxActual += v[i];
            fin = i;
        }

        /// Si la suma actual es mayor que la suma global, actualizamos la suma global
        /// y los índices de inicio y fin del subvector
        if(maxActual > maxGlobal){
            maxGlobal = maxActual;
            inicioMax = inicio;
            finMax = fin;
        }
        for(int j = 0; j < n; j++){
            if(j >= inicioMax && j <= finMax){
                vSMax[j] = v[j]; /// Guardamos el subvector de suma máxima
            }
            else{
                vSMax[j] = 0; /// Resto del vector se llena con ceros

            }
        }

    }
};

int main(int argc, char const *argv[])
{
    int n = 8;
    int vAux[] = {-2,-5,6,-2,-3,1,5,-6};

    int *v = new int[n];
    for (int i = 0; i < n; i++){
        v[i] = vAux[i]; /// Inicialización del vector
    }
    int *vSMax = new int[n]{0}; /// Declaración de un vector donde se guardará la suma máxima

    /// LLamada a la función para encontrar la suma máxima
    subSumaMaxima(v, n, vSMax);
    /// mostrando el vector
    cout << "Vector: [";
    for(int i = 0; i < n; i++){
        cout << v[i];
        if(i != n-1){cout << ",";}
    }
    cout << "]" << endl;

    /// mostrando el vector de suma máxima
    cout << "Vector de suma máxima: [";
    for(int i = 0; i < n; i++){
        cout << vSMax[i];
        if(i != n-1){cout << ",";}
    }
    cout << "]" << endl;

    /// Liberar la memoria
    delete[] v;
    delete[] vSMax;
    
    return 0;
}
