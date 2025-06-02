#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>

using namespace std;

void algoritmoGreddy(const vector<vector<int>>& v, vector<int>& rGreedy, int f, int c)
{
    int suma = 0;
    int numeroMenor = v[f/2][0]; // Inicializar numeroMenor con el valor del centro de la primera columna
    // Aplicacion de Heuristica:
    for (int i=0; i < c; i++)
    {
        numeroMenor = v[f/2][i]; // Reiniciar el numeroMenor para la siguiente columna con el valor del centro de la columna
        cout << "Primer numero de la columna <" << i << "> : " << numeroMenor << endl;
        for (int j=0; j < f; j++)
        {
            cout << "   " <<suma<<"+"<<numeroMenor<< " -- " << suma<<"+"<<v[j][i] <<endl; // Good 
            if(numeroMenor+suma > v[j][i]+suma){
                cout << "   → Hay un camino mas Factible: " << v[j][i] << endl;
                numeroMenor = v[j][i];
            }
        }
        rGreedy.push_back(numeroMenor); // Guardar el valor menor en el vector de resultados
        suma += numeroMenor; // Sumar el valor menor a la suma total
        cout << "Numero mas Factible: " << numeroMenor << endl;
        cout << "Suma acumulada: " << suma << endl;
        cout << endl;
    }
}
void imprimirMatriz(const vector<vector<int>>& v, int f, int c)
{
    cout << "Matriz de entrada:";
    cout << "\n ";
    for(int i = 0; i < c; i++){
       cout << "__";
    }
    cout << endl;
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            if(j == 0 ){
                cout<< "|" << v[i][j] << " ";
            }else if(j == c-1){
                cout << v[i][j] << "|";
            }else{
                cout << v[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int f,c;
    vector<vector<int>> v;
    vector<int> rGreedy;

    if(argc < 4){
        cout<<"Error: No se han introducido suficientes argumentos."<<endl;
        cout<<"Uso: "<<argv[0]<<" <f> <c> <elementos...>"<<endl;
        return 1;
    }

    f = atoi(argv[1]);
    c = atoi(argv[2]);
    v.resize(f, vector<int>(c));

    for(int i = 0; i<f; i++){
        for(int j = 0; j<c; j++){
            v[i][j] = atoi(argv[3 + i*c + j]);
        }
    }

    auto start = std::chrono::high_resolution_clock::now();

    algoritmoGreddy(v, rGreedy, f, c);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = end - start;

    imprimirMatriz(v, f, c);

    cout << "Solución Greedy: ";
    for(int i = 0; i < rGreedy.size(); i++){
        cout << "["<< rGreedy[i];
        if (i < rGreedy.size() - 1) {
            cout << "],";
        }
    }
    cout << "]" << endl;

    cout << "Tiempo de ejecución: " << duracion.count() << " segundos" << endl;
    cout << "Suma total: " << accumulate(rGreedy.begin(), rGreedy.end(), 0) << endl;

    return 0;
}
