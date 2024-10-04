#include <iostream>
#include <math.h>

using namespace std;

#define A 20
#define B 10
#define C 15

int main() {
	
	int d = A+B+C;
	cout<< d<<"\n";
	if(d%2 == 0) {
		cout<<"El número es par\n";
	}else{
			cout<<"El número es impar\n";
	}
	return 0;
}
