#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Vendedor {
    int seccion;
    int numero;
    string nombreApellido;
    string ultimoMes;
    string proceso;
};

struct Venta {
    int seccion;
    int numero;
    int rubro;
    float montoVendido;
    string mes;
    string proceso;
};

struct Comision {
    float comisionRubro1;
    float comisionRubro2;
    float comisionRubro3;
};

void calcularComisiones(vector<Vendedor>& vendedores, const vector<Venta>& ventas, const Comision& comisiones) {
    ofstream salida("informe.txt");
    float totalGeneralComisiones = 0;

    if (!salida.is_open()) {
        cout << "Error al abrir el archivo de salida." << endl;
        return;
    }

    salida << left << setw(10) << "SECCIÓN" << setw(10) << "Nº VENDEDOR" << setw(25) << "NOMBRE Y APELLIDO" << setw(15) << "COMISIÓN" << setw(15) << "OBSERVACIONES" << endl;

    for (const auto& vendedor : vendedores) {
        float comision = 0;
        bool ventasRealizadas = false;

        for (const auto& venta : ventas) {
            if (vendedor.numero == venta.numero) {
                ventasRealizadas = true;
                float comisionRubro = 0;
                switch (venta.rubro) {
                    case 1:
                        comisionRubro = comisiones.comisionRubro1;
                        break;
                    case 2:
                        comisionRubro = comisiones.comisionRubro2;
                        break;
                    case 3:
                        comisionRubro = comisiones.comisionRubro3;
                        break;
                    default:
                        break;
                }
                comision += venta.montoVendido * comisionRubro;
            }
        }

        salida << left << setw(10) << vendedor.seccion << setw(10) << vendedor.numero << setw(25) << vendedor.nombreApellido << setw(15) << fixed << setprecision(2) << comision;
        
        if (!ventasRealizadas) {
            salida << "*";
        }
        
        salida << endl;

        totalGeneralComisiones += comision;
    }

    salida << "TOTAL GENERAL DE COMISIONES: " << fixed << setprecision(2) << totalGeneralComisiones << endl;
    salida.close();
}

int main() {
    // Leer datos de los archivos de vendedores y ventas
    // Suponiendo que tienes las funciones para cargar los datos de los archivos

    vector<Vendedor> vendedores; // Vector de vendedores
    vector<Venta> ventas; // Vector de ventas

    // Cargar datos de los archivos

    Comision comisiones = {0.05, 0.07, 0.1}; // Definir las comisiones por rubro

    calcularComisiones(vendedores, ventas, comisiones);

    // Actualizar archivo maestro con los nuevos datos

    return 0;
}
