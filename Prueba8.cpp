#include <iostream>

#define multiplicacion(a,b) a*b //Es como un mini proceso. '(a,b)' serían los parámetros y 'a*b' la acción a realizar.

using namespace std;

int main(){
	
	int multiplicar = multiplicacion(4,5);
	cout<<multiplicar;
	
	return 0;
}
