#include <iostream>

using namespace std;

int BusquedaBinaria(const int *v, int start, int end, int elem){
	int centro;
	if(start>end){return -1;}
	centro = (start+end)/2;
	if(v[centro] == elem){return centro;}
	else if(v[centro] > elem){
		return BusquedaBinaria(v,start,centro-1,elem);
	}else{
		return BusquedaBinaria(v,centro+1,end,elem);
	}

	cout << "No se encontro el elemento" << endl;
	return -1;
};

int main(){
	int n = 10;
	int elem;
	int *v = new int[n];
	for(int i = 0; i<n; i++){
		v[i] = i;
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "Ingrese el elemento a buscar: ";
	cin >> elem;
	if(elem < 0 || elem >= n){
		cout << "El elemento no se encuentra en el rango del vector" << endl;
		delete v;
		return 0;
	}
	int posElem = BusquedaBinaria(v,0,n,elem);
	cout<<"El elemento "<< elem <<" se encuentra en la posicion: "<<posElem+1<<endl;
	delete v;
	return 0;
}
