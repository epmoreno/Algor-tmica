#include <iostream>
#include <climits>

struct Resultado {
    int suma;
    int inicio;
    int fin;
};

Resultado max_crossing_sum(int arr[], int bajo, int medio, int alto) {
    int suma_izq = INT_MIN;
    int suma_der = INT_MIN;
    int suma_actual = 0;
    int inicio_izq = medio;
    
    // Calcular suma máxima desde el medio hacia la izquierda
    for (int i = medio; i >= bajo; i--) {
        suma_actual += arr[i];
        if (suma_actual > suma_izq) {
            suma_izq = suma_actual;
            inicio_izq = i;
        }
    }
    
    suma_actual = 0;
    int fin_der = medio + 1;
    
    // Calcular suma máxima desde el medio hacia la derecha
    for (int i = medio + 1; i <= alto; i++) {
        suma_actual += arr[i];
        if (suma_actual > suma_der) {
            suma_der = suma_actual;
            fin_der = i;
        }
    }
    
    return {suma_izq + suma_der, inicio_izq, fin_der};
}

Resultado max_subarray(int arr[], int bajo, int alto) {
    // Caso base: vector de un solo elemento
    if (bajo == alto) {
        return {arr[bajo], bajo, alto};
    }
    
    int medio = (bajo + alto) / 2;
    
    // Resolver recursivamente las dos mitades
    Resultado izq = max_subarray(arr, bajo, medio);
    Resultado der = max_subarray(arr, medio + 1, alto);
    
    // Calcular la suma máxima que cruza el punto medio
    Resultado cruzando = max_crossing_sum(arr, bajo, medio, alto);
    
    // Determinar qué resultado es mayor
    if (izq.suma >= der.suma && izq.suma >= cruzando.suma) {
        return izq;
    } else if (der.suma >= izq.suma && der.suma >= cruzando.suma) {
        return der;
    } else {
        return cruzando;
    }
}

// Función principal para probar el algoritmo
void encontrar_maximo_subvector(int arr[], int tamano) {
    Resultado resultado = max_subarray(arr, 0, tamano - 1);
    
    std::cout << "Vector original: ";
    for (int i = 0; i < tamano; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Suma máxima: " << resultado.suma << "\n";
    std::cout << "Índice inicio: " << resultado.inicio << "\n";
    std::cout << "Índice fin: " << resultado.fin << "\n";
    
    std::cout << "Subvector máximo: ";
    for (int i = resultado.inicio; i <= resultado.fin; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// Ejemplo de uso
int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int tamano = sizeof(arr)/sizeof(arr[0]);
    
    encontrar_maximo_subvector(arr, tamano);
    
    return 0;
}