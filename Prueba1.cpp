#include <iostream>

using namespace std; //El 'using namespace' ayuda a no tener que repetir, en este caso, el 'std' todo el tiempo.
// Tenemos 5 tipos de datos: int, char, float, double y bool.
int main() {
	int edad = 0;
	for(int i=0; i <= 80; i++){	
	// el cout hace que muestre en consola (c-out) (out es afuera en inglés).	
		cout<<" Tengo "<<edad<<" años \n"; // Se usan los signos '<<' para separar los textos/variables/etc.
		edad++; // el '++' es para sumar 1 a la variable, en este caso, 'edad'. Para restar 1 usaríamos '--'.
	
	
	return 0;
}