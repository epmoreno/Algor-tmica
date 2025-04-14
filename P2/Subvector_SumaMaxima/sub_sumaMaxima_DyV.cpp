#include <iostream>
#include <climits>
using namespace std;

struct Resultado {
    int suma;   // Suma máxima del subvector
    int inicio; // Índice de inicio del subvector
    int fin;    // Índice de fin del subvector
};

// Función para calcular la suma máxima cruzando el medio
Resultado max_cruce_sum(int v[], int inicio, int medio, int fin){ 
   
    // Calcular la suma máxima en la parte izquierda
    int suma_izq = INT_MIN;
    int suma_actual = 0;
    int inicio_izq = medio;
    for(int i = medio; i >= inicio; i--){
        suma_actual += v[i];
        if(suma_actual > suma_izq){
            suma_izq = suma_actual;
            inicio_izq = i;
        }
    }

    // Calcular la suma máxima en la parte derecha
    int suma_der = INT_MIN;
    suma_actual = 0;
    int fin_der = medio + 1;
    for (int i = medio+1; i <= fin; i++)
    {
        suma_actual += v[i];
        if(suma_actual > suma_der){
            suma_der = suma_actual;
            fin_der = i;
        }
    }
    return {suma_izq + suma_der, inicio_izq, fin_der};
}

// Función recursiva para encontrar el subvector con la suma máxima
// Se calcula la solucion para comparando los resultados de las dos mitades y el resultado cruzando el medio
// Se devuelve el resultado con la mayor suma
Resultado max_subvector(int v[], int inicio, int fin){
    // caso base: vector de un solo elemento
    if(inicio == fin){
        return {v[inicio], inicio, fin};
    }

    int medio = (inicio + fin) / 2;

    // Resolver recursivamente las dos mitades
    Resultado izq = max_subvector(v, inicio, medio);
    Resultado der = max_subvector(v, medio + 1, fin);

    // Calcular la suma máxima que cruza el punto medio
    Resultado cruzando = max_cruce_sum(v, inicio, medio, fin);

    // Determinar qué resultado es mayor
    if(izq.suma >= der.suma && izq.suma >= cruzando.suma){
        return izq;
    } else if(der.suma >= izq.suma && der.suma >= cruzando.suma){
        return der;
    } else {
        return cruzando;
    }
}

int main(int argc, char const *argv[])
{
    //int v[] = {-2, -5, 6, -2, -3, 1, 5, -6};                // Vector que cruza el punto medio
    int v[] = {8, -5, 6, -2, -3, 1, -6, -6};           // Vector que no cruza el punto medio
    //int v[] = {-2, -5, -2, -2, 6, 1, 5, -6};
    int n = sizeof(v) / sizeof(v[0]);                       // Calcular el tamaño del vector
    Resultado resultado = max_subvector(v, 0, n - 1);       // Llamada a la función para encontrar el subvector con la suma máxima
    
    cout << "Vector original: [";
    for(int i = 0; i < n; i++){
        cout << v[i];
        if(i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Suma máxima: " << resultado.suma << endl;      // Mostrar la suma máxima
    cout << "Índice inicio: " << resultado.inicio << endl;  // Mostrar el índice de inicio
    cout << "Índice fin: " << resultado.fin << endl;        // Mostrar el índice de fin
    
    cout << "Subvector máximo: [";
    for(int i = resultado.inicio; i <= resultado.fin; i++){
        cout << v[i];
        if(i < resultado.fin) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
