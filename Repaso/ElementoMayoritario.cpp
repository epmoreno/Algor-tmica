#include <iostream>

using namespace std;

int contador(const int *v, int inicio, int fin, int elem){
    int contador = 0;
    for(int i = inicio; i <= fin; i++){
        if(v[i] == elem){
            contador++;
        }
    }
    return contador;
}

int MayorRepeticion(const int *v, int inicio, int fin){
    if(inicio == fin){
        return v[inicio]; // Base case: only one element
    }
    
    int medio = inicio + (fin - inicio) / 2;
    int elemIzq = MayorRepeticion(v, inicio, medio);
    int elemDer = MayorRepeticion(v, medio + 1, fin);
    
    if(elemIzq == elemDer){
        return elemIzq; // If both elements are the same, return either
    }

    int countIzq = contador(v, inicio, fin, elemIzq);
    int countDer = contador(v, inicio, fin, elemDer);
    
    return (countIzq > countDer) ? elemIzq : elemDer; // Return the element with the highest count
}


int main(int argc, char const *argv[])
{
    if(argc < 3){
        cout << "Uso: ./" << argv[0] <<" <n> <elemnto1> <elemento2> ... <elementoN>" << endl;
        return 1;
    }
    int n = atoi(argv[1]);
    int *v = new int [n];
    for(int i = 0; i < n; i++){
        v[i] = atoi(argv[i+2]); // Initialize the array with values from command line arguments
        cout << v[i] << " ";
    }
    cout << endl;
    int mayor = MayorRepeticion(v, 0, n - 1);
    int contadorMayor = contador(v, 0, n - 1, mayor);
    if(contadorMayor >= n / 2){
        cout << "El elemento mayoritario es: " << mayor << " con " << contadorMayor << " repeticiones." << endl;
    } else {
        cout << "No hay elemento mayoritario." << endl;
    }

    delete[] v;
    return 0;
}
