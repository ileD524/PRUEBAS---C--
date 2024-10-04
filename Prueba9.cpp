#include <iostream>
#include <clocale> // Permite usar el 'setlocale'.

using namespace std;
int main() {
	
	setlocale(LC_CTYPE, "spanish"); //El 'setlocale' nos permite usar letras que están en español (ñ) y los acentos. Disque.
	cout<<"aceptó sí o ño";
	return 0;
	
}