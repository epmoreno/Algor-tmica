#include <iostream>
#include <vector>
#include <algorithm> // Para min

using namespace std;

// Función para encontrar el número mínimo de monedas para una cantidad N
vector<int> cambioMonedas(int N, const vector<int>& d) {
    int n = d.size();
    vector<int> dp(N + 1, N + 1); // N + 1 es un valor "infinito" ya que la máxima cantidad de monedas posible es N (si solo hay monedas de 1)
    dp[0] = 0; // caso base: 0 monedas para la cantidad 0

    vector<int> parent(N + 1, -1); // Para reconstruir la solución, guardamos qué moneda usamos para cada cantidad

    for(int a : dp){
        cout << a << " "; // Imprimir el contenido de dp para depuración
    }
    cout << endl;
    for(int b : parent){
        cout << b << " "; // Imprimir el contenido de parent para depuración
    }
    cout << endl;


    // Llenar la tabla dp
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < n; ++j) {
            // Si la moneda d[j] es menor o igual a la cantidad actual i
            // y si usar esta moneda mejora la solución para i
            if (d[j] <= i && dp[i - d[j]] + 1 < dp[i]) {
                dp[i] = dp[i - d[j]] + 1;
                parent[i] = d[j]; // Guardamos la moneda que usamos
            }
        }
    }
    for(int a : dp){
        cout << a << " "; // Imprimir el contenido de dp para depuración
    }
    cout << endl;
    for(int b : parent){
        cout << b << " "; // Imprimir el contenido de parent para depuración
    }
    cout << endl;
    // Si dp[N] sigue siendo N + 1, significa que no se puede formar la cantidad N
    if (dp[N] == N + 1) {
        cout << "No se puede formar la cantidad N = " << N << " con las monedas dadas." << endl;
        return {}; // Devolver un vector vacío para indicar que no hay solución
    }

    // Reconstruir la solución usando el array parent
    vector<int> resultadoMonedas(n, 0); // Para almacenar el recuento de cada tipo de moneda
    int currentAmount = N;
    while (currentAmount > 0) {
        int monedaUsada = parent[currentAmount];
        
        // Encontrar el índice de la moneda usada en el vector d
        for (int k = 0; k < n; ++k) {
            if (d[k] == monedaUsada) {
                resultadoMonedas[k]++;
                break;
            }
        }
        currentAmount -= monedaUsada;
    }

    return resultadoMonedas;
}

int main() {
    // Ejemplo de uso:
    vector<int> d = {1, 2, 5, 10, 20, 50, 100}; // Valores de las monedas (ordenadas y d1=1)
    int N = 73; // Cantidad a devolver

    cout << "Monedas disponibles: ";
    for (int val : d) {
        cout << val << " ";
    }
    cout << "\nCantidad a devolver: " << N << endl;

    vector<int> resultado = cambioMonedas(N, d);

    if (!resultado.empty()) {
        int totalMonedas = 0;
        cout << "Solucion para " << N << ":" << endl;
        for (size_t i = 0; i < resultado.size(); ++i) {
            if (resultado[i] > 0) {
                cout << "  " << resultado[i] << " moneda(s) de " << d[i] << endl;
                totalMonedas += resultado[i];
            }
        }
        cout << "Numero total de monedas: " << totalMonedas << endl;
    }

    // cout << "\n--- Ejemplo sin solucion ---\n";
    // vector<int> d3 = {5, 10}; // No tiene moneda de 1
    // int N3 = 7;
    // cout << "Monedas disponibles: ";
    // for (int val : d3) {
    //     cout << val << " ";
    // }
    // cout << "\nCantidad a devolver: " << N3 << endl;
    
    // vector<int> resultado3 = cambioMonedas(N3, d3);
    // La función ya imprime el mensaje de "no se puede"
    
    return 0;
}
