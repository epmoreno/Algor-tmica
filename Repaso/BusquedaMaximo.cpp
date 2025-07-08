#include <iostream>

using namespace std;

int BusquedaMaximo(const int *v, int inicio, int fin){
    if(inicio == fin){
        return v[inicio];
    }

    int medio = inicio + (fin -inicio) /2;
    cout << "Medio: " << medio << ", Inicio: " << inicio << ", Fin: " << fin << endl; // Debugging output
    int maxIzq = BusquedaMaximo(v, inicio, medio);
    cout << "Maximo izquierdo: " << maxIzq << endl; // Debugging output
    int maxDer = BusquedaMaximo(v, medio + 1, fin);
    cout << "Maximo derecho: " << maxDer << endl; // Debugging output
    return (maxIzq > maxDer) ? maxIzq : maxDer; // Return the maximum of the two halves
}

int main(int argc, char const *argv[])
{
    if(argc < 3){
        cout << "Uso: " << argv[0] << " <n> <elem1> <elem2> ... <elemN>" << endl;
        return 1;
    }
    int n = atoi(argv[1]);
    int *v = new int[n];
    for(int i = 0; i < n; i++){
        v[i] = atoi(argv[i+2]); // Initialize the array with values 1 to n
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "El elemnto maximo del array es: \n" << BusquedaMaximo(v, 0, n-1)<<endl;
    delete[] v;
    return 0;
}

