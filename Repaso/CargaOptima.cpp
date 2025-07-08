#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int AlgoritmoCargaOptima(vector<int> &contenedores, int n, int k){
    sort(contenedores.begin(), contenedores.end());
    int suma = 0, contador = 0;

    for(int peso : contenedores){
        if(suma + peso <= k){
            suma += peso;
            contador++;
        } else {
            break; // No se puede agregar más peso sin exceder el límite
        }
    }
    return contador;
};

int AlgoritmoMaximaCarga(vector<int> &contenedores, int n, int k){
    sort(contenedores.rbegin(), contenedores.rend());
    int suma = 0;
    for(int i = 0; i < n; i++){
        if(suma +  contenedores[i] <= k){
            suma += contenedores[i];
        }
    }
    return suma;
};   

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<int> contenedores(n);
    for (int i = 0; i < n; i++)
    {
        cin >> contenedores[i];
    }
    
    int cargaOptima = AlgoritmoCargaOptima(contenedores, n, k);
    int maximaCarga = AlgoritmoMaximaCarga(contenedores, n, k);

    cout << cargaOptima << endl;
    cout << maximaCarga << endl;
    return 0;
}
