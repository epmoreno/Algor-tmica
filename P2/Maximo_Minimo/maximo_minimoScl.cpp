#include <iostream>

using namespace std;


void encontrar_maximo_minimo(int v[], int n, int &maxIdx, int &minIdx, int &maX, int &miN){
    // Caso base para un y dos elementos
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
    // Caso genearl n mayor a 2
    else{
        // Se inicializa los maximo y minimo e indices respectivos en la primera posicion
        maX = v[0];
        miN = v[0];
        maxIdx = 0;
        minIdx = 0;

        for(int i = 1; i < n; i++){ // Se recorre el vector empezando desde la segunda posicion
            // Se encuentra el maximo
            if(v[i]>maX){
                maX = v[i];
                maxIdx = i;
            }
            // Se encuentra el minimo
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
    int v[n] = {5,904,10,100,13,54,905}; // Declaración de los elementos del vector        
    int idx_max, idx_min, max, min;

    encontrar_maximo_minimo(v, n, idx_max, idx_min, max, min); // Llamada a la función para encontrar el máximo y mínimo

    //Final:
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
