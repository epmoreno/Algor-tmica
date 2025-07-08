#include <iostream>
using namespace std;

int ExponenciacionRapida(int base, int exponente){
    if(exponente==0){
        // cout << "Caso base alcanzado: exponente es 0, retornando 1" << endl; // Debugging output
        return 1;
    }
    // cout <<"Base: " << base << ", Exponente: " << exponente << endl;
    int temp = ExponenciacionRapida(base, exponente / 2);
    // cout <<"temp: "<<temp<<", Base: " << base << ", Exponente: " << exponente << endl; // Debugging output
    if(exponente % 2 == 0){
        // cout << temp << " * " << temp << endl; // Debugging output
        return temp * temp;
    }else{
        // cout << base << " * " << temp << " * " << temp << endl; // Debugging output
        return base * temp * temp;
    }
}

int main(int argc, char const *argv[])
{
    if(argc < 3) {
        cout << "Uso: " << argv[0] << " <base> <exponente>" << endl;
        return 1;
    }
    int base = atoi(argv[1]);
    int exponente = atoi(argv[2]);
    int result = ExponenciacionRapida(base, exponente);
    cout << "Resultado: " << result << endl;
    return 0;
}
