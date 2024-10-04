#include <iostream>

using namespace std;

int main() {
	
	int edad = 0;
	
	cout<<"Ingrese su edad: ";
	cin>> edad;
	cout<<"\n\n";
	if(edad>=18){
		cout<<"Puede ingresar\n";
	}else{
		cout<<"¡USTED ES MENOR DE EDAD!. Vuelva cuando crezca :).\n";
	}
	
	return 0;
}