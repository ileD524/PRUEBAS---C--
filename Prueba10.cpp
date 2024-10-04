#include <iostream>

using namespace std;

int main() {
	
	int prueba [4], a;
	
	for(int i=0; i<=4; i++){
		cout<<"Ingrese un dato: ";
		cin>>a;
		prueba[i]= a;
	}
	cout<<"Los datos que ingresaste son: \n";
	for(int i=0; i<=4; i++){
		cout<<prueba[i]<<endl;
	}
	return 0;
}