#include <iostream>

using namespace std;

int main(){
	bucle:
	int opcion = 0;
	cout<<"Elige una opcion del 1 al 3: ";
	cin>>opcion;
	cout<<"\n\n";
	
	switch(opcion){
		
		case 1:
			cout<<"Elegiste la opcion 1";
			break;
		case 2:
			cout<<"Elegiste la opcion 2";
			break;
		case 3:
			cout<<"Elegiste la opcion 3";
			break;
		default:
			cout<<"DEL 1 AL 3 TE DIJE\n\n";
			goto bucle;
			break;
	
	}
	
	return 0;
}