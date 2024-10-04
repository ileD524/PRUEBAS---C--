#include <iostream> //Esta librería nos permite la entrada y salida de datos.
#include <string> //Esta librería nos permite manejar de una mejor forma los 'strings'.
#include <fstream> //Esta librería está relacionada con los archivos. Nos permite leer, modificar, abrir y cerrrar los archivos (entre otros).
#include <iomanip> //Este nos permite manejar los datos de salida (setprecision()). 

using namespace std;

//Declaración de registros.
struct Detalle{
		string seccion[20];
		int vendedor;
		float montoVendido;
		int mesProceso;
		int rubro;
};
struct Maestro {
    string seccion[20];
    int vendedor;
    string nombreApellido[50];
    int ultimoMesProceso;
};
struct resumen {
	string seccion;
	int vendedor;
	string nombreApellido;
	float comision;
};

//Procesos de carga de los registros.
void cargaM(int n, struct Maestro mae[]) {
    
    for (int i = 0; i < n; i++) {
        mae[i].vendedor = i + 1;
		cout<<endl<<endl;
        cout << "Ingrese la seccion a la que pertenece el vendedor #" << i + 1 << ": ";
        cin >> mae[i].seccion[i];
        
        cout << "Ingrese el nombre y el apellido del vendedor #" << i + 1 << ": ";
        cin.ignore(); // Para evitar problemas con la lectura de strings
        getline(cin, mae[i].nombreApellido[i]);
        
        cout << "Ingrese el ultimo mes en el que fue la ultima venta: ";
        cin >> mae[i].ultimoMesProceso;
    }
}
void cargaD(int m, Detalle det[]){
	
	for (int j = 0; j < m; j++) {
		cout<<endl<<endl;
		cout<<"Venta #"<<j + 1<<endl;
        cout << "Ingrese la seccion a la que pertenece el vendedor: ";
        cin >> det[j].seccion[j];
        
        cout << "Ingrese el numero del vendedor: ";
        cin >> det[j].vendedor;
        
        cout << "Ingrese el ultimo mes en el que fue la ultima venta: ";
        cin >> det[j].mesProceso;
        
        cout<<"Ingrese el rubro al que pertenece el vendedor: ";
        cin>> det[j].rubro;
		
		cout<<"Ingrese el monto vendido: ";
		cin>> det[j].montoVendido;
    }
}

//proceso para crear el informe.
void informar(int n, int m, Maestro mae[], Detalle det[], resumen res[]) {
    ofstream archivo("informe.word", ios::out | ios::app); 

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    float totalGeneralComisiones = 0; 
    int i=0, j=0, k=0;

	while(i<n){
		float comision = 0, monto=0, comisionTotal = 0;
		while(j<m && det[j].vendedor == mae[i].vendedor){
			monto += det[j].montoVendido;
			j++;
		}
		 if (monto > 0) {
        	
        	if(det[j-1].rubro == 1){
        		comision = monto * 0.3;
			}else if(det[j-1].rubro == 2){
				comision = monto * 0.2;
			}else{
				comision = monto * 0.1;
			}
			
			comisionTotal += comision;
            totalGeneralComisiones += comision;
        }
    	
        char obs = (monto == 0) ? '*' : '-';
        
        res[k].seccion = mae[i].seccion[i];
        res[k].vendedor = mae[i].vendedor;
        res[k].nombreApellido = mae[i].nombreApellido[i];
        res[k].comision = comisionTotal;
        
        archivo << fixed << setprecision(2);
        
		archivo << endl;
		archivo << "---------------------------------INFORME---------------------------------";
		archivo << endl;
        archivo << "SECCIÓN: " << mae[i].seccion[i]<< endl;
        archivo << "VENDEDOR: " << mae[i].vendedor << endl;
        archivo << "NOMBRE Y APELLIDO: " << mae[i].nombreApellido[i] << endl;
        archivo << "MONTO VENDIDO: " << fixed << setprecision(2) << monto << endl; 
        archivo << "COMISIÓN: " << fixed << setprecision(2) << comision << endl;
        archivo << "OBSERVACIÓN: " << obs << endl << endl;
        
        cout<<endl<<"RESUMEN DEL VENDEDOR #"<<res[k].vendedor<<endl<<endl
			<<"SECCION: "<<res[k].seccion<<endl
            <<"NOMBRE Y APELLIDO: "<<res[k].nombreApellido<<endl
            <<"COMISION: "<<fixed<<setprecision(2)<<res[k].comision<<endl;
            
        i++;
    }

    archivo << "TOTAL GENERAL DE COMISIONES: " << setprecision(2) << totalGeneralComisiones << endl;
    archivo.close();
}

//Programa principal.
int main(){
    int n, m;  
    
    //LLamar a los procesos de carga de los registros.
    cout<<endl<<"Los siguientes datos a ingresar son para el registro MAESTRO"<<endl<<endl;
    cout << "Ingrese el numero de datos que va a cargar: ";
    cin >> n; 

    struct Maestro mae[n];
	cargaM(n, mae);
	
	
	cout<<endl<<"Los siguientes datos a ingresar son para el registro DETALLE"<<endl<<endl;
	cout<<"Ingrese el numero de ventas nuevas que va a cargar: ";
	cin>> m;
	
	struct Detalle det[m];
	cargaD(m, det);
	
	struct resumen res[n];

	//Llamar al proceso para crear el informe y el resumen.
	informar(n, m, mae, det, res);

	//Terminar.
    return 0;
}
