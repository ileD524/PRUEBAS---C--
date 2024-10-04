#include <iostream>

#define PI 3,1416 // El '#define' es una analogía del '.eqv'. Se usa para definir constantes.

using namespace std;

int main() {
	
	const float GRAVEDAD = 9.8; // Las constantes siempre van en mayúsculas. Más que nada por comodidad visual de los programadores.
	
	/*
	 También podemos usar el 'const' para definir constantes. 
	En este caso, hay que definir también el tipo de datos con el que estamos trabajando ('float').
	*/
	
	cout<< GRAVEDAD<<"\n"<<PI;
	return 0;
}
