#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int OptimizacionTiemposReparaciones(vector<int> &tiempos){
    sort(tiempos.begin(), tiempos.end());
    int tiempoTotal = 0;
    int acumulado = 0;
    int n = tiempos.size();

    for(int i = 0; i < n; i++){
        acumulado += tiempos[i];
        tiempoTotal += acumulado;
    }
    return tiempoTotal;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> tiempos(n);
    for (int i = 0; i < n; i++) {
        cin >> tiempos[i];
    }
    cout << OptimizacionTiemposReparaciones(tiempos) << endl;
    return 0;
}
