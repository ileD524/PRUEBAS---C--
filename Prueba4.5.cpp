#include <iostream>
#include <math.h> //Nos permite usar 'pow()'.
#include <iomanip> //Nos permite usar 'setprecision'.

//Este programa es igual a la 'Prueba4', solo que con algunas cosas cambiadas.

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
	
	imc = peso/ pow(altura,2);// La librería 'math.h' nos permite usar 'pow' para hacer las potencias.
	cout<<"Su Indice de Masa Corporal(IMC) es: "<<setprecision(4)<<imc<<"\n\n"; 
	//'setprecision' aproxima el resultado a, en este caso, 4 números.
	
	return 0;
}