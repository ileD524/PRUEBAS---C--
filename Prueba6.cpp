#include <iostream>

using namespace std;

int main(){
	
	int horas;
	cout<<"Ingrese la cantidad de horas que trabajaste: ";
	cin>>horas;
	
	if(horas<5){
		cout<<"Ganaste solo 500 pesos";
	}else if(horas>=5 && horas<=10){
		cout<<"Ganaste 1000 pesos";
	}else{
		cout<<"Ganaste 5000 pesos";
	}
	
	return 0; 
}