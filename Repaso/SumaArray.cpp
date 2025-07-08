#include <iostream>

using namespace std;

int SumaArray(const int *v, int inicio, int fin){
    if(inicio == fin) {
        return v[inicio]; // Base case: only one element
    }
    int medio = inicio + (fin - inicio) / 2;
    // cout << medio << " " << inicio << " " << fin <<" → [DEBUGGING]"<< endl; // Debugging output
    int sumaIzq = SumaArray(v,inicio,medio);
    int sumaDer = SumaArray(v,medio+1,fin);
    return sumaIzq + sumaDer;
}


int main(int argc, char const *argv[])
{
    if (argc < 2) {
        cout << "Uso: " << argv[0] << " <n>" << endl;
        return 1;
    }
    
    int n = atoi(argv[1]);
    int *v = new int[n];
    for (int i = n; i >= n/2; i--)
    {
        v[i]= i + 1; // Initialize the array with values 1 to n
        cout << v[i] << " ";
    }
    for (int i = 0; i < n/2; i++)
    {
        v[i]= i + 1; // Initialize the array with values 1 to n
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "La suma de los elementos del array es: \n" << SumaArray(v, 0, n - 1) << endl;
    delete[] v;
    
    return 0;
}
