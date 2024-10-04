#include <iostream>

using namespace std;

int main() {
	
	float peso = 0;
	float altura = 0;
	float imc = 0;
	
	cout<<"Calculadora de Indice de Masa Corporal (IMC)\n\n";
	cout<<"Ingrese su peso en kilogramos: ";//Analogía de 'PRINT_INT'.
	cin>>peso; //'cin' le da el espacio al usuario para que ingrese la info. Analogía de 'READ_STRING'.
	cout<<"\n\n";
	cout<<"Ingrese su altura en metros: ";
	cin>>altura;
	cout<<"\n\n";
	
	altura *= altura; //El '*=' indica que estamos haciendo 'altura = altura*altura'.
	imc = peso/altura;// Acá estamos dividiendo.
	cout<<"Su Indice de Masa Corporal(IMC) es: "<< imc<<"\n\n";
	
	return 0;
}