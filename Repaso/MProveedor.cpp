#include <iostream>
#include <vector>
using namespace std ;
int calcularVisitas ( vector <int> dias , int n , int r ) {
    int visitas = 0;
    int i = 0; // Í ndice del ú ltimo d í a visitado
    int diaActual = dias [0]; // Primera visita obligatoria
    ++ visitas ;
    int j = i + 1;
    while (1) {
        while ( j < n && dias [ j ] - diaActual <= r ) {
            j ++;
        }
        if ( j < n ) {
            diaActual = dias [j -1];
            i = j -1;
            ++ visitas ;
        } else {
            break ;
        }
    }
    return visitas ;
}
int main () {
    int n , r ;
    cin >> n >> r ;
    vector < int > dias ( n ) ;
    for ( int i = 0; i < n ; ++ i ) {
        cin >> dias [ i ];
    }
    cout << calcularVisitas ( dias , n , r ) << endl ;
    return 0;
}