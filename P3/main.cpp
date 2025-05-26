#include <iostream>
#include <vector>

using namespace std;

vector<int> esFactible(vector<vector<int>>& v, int f, int c)
{
    cout << "   Comprobando factibilidad..." << endl;
    vector<int> rFactible;
    int suma = 0;
    // Aplicacion de Heuristica:
    for (int i=0; i < c; i++)
    {
        for (int j=1; j < f; j++)
        {
            cout <<suma<<"+"<<v[j-1][i]<< "   " << suma<<"+"<<v[j][i] <<"; "; // Good 
            if((suma+v[j-1][i])<(suma+v[j][i])){
                // cout << "Numero menor: " << v[j-1][i] << " ";
                suma += v[j-1][i];
                rFactible.push_back(v[j-1][i]); // Guardar el valor en el vector de resultados
                cout << "Suma izq= " << suma << endl;
            }else if ((suma+v[j-1][i])>=(suma+v[j][i])){
                // cout << "Numero menor: " << v[j][i] << " ";
                suma += v[j][i];
                rFactible.push_back(v[j][i]); // Guardar el valor en el vector de resultados
                cout << "Suma der= " << suma << endl;
            }
            
        }
        cout << endl;
    }
    return rFactible;
}


void algoritmoGreddy(vector<vector<int>>& v, vector<int>& rGreedy, int f, int c)
{
    cout << "Aplicando algoritmo Greedy..." << endl;

    // Alforitmo Greddy:
    vector<vector<int>> mAux = v; // Copia de la matriz original
    int i = 0, j = 0;

    rGreedy = esFactible(mAux, f, c); // Llamada a la función esFactible
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

    algoritmoGreddy(v, rGreedy, f, c);

    cout << "Solución Greedy: ";
    for(int i = 0; i < rGreedy.size(); i++){
        cout << "["<< rGreedy[i];
        if (i < rGreedy.size() - 1) {
            cout << "],";
        }
    }
    cout << "]" << endl;

    return 0;
}
