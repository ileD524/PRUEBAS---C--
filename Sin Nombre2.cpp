#include <iostream>
#include <iomanip>
#include <libxl.h> // Asegúrate de haber instalado la librería libxl

using namespace libxl;

int main() {
    Book* book = xlCreateBook();
    if (book) {
        if (book->load("VENDEDORES.xlsx")) { // Reemplaza "nombre_del_archivo_excel.xlsx" con el nombre de tu archivo Excel
            Sheet* sheet1 = book->getSheet(0); // Suponiendo que los datos están en la primera hoja

            if (sheet1) {
                // Obtener el número de filas y columnas
                int rowCount = sheet1->lastRow();
                int colCount = sheet1->lastCol();

                std::cout << "SECCIÓN Nº VENDEDOR NOMBRE Y APELLIDO COMISIÓN OBSERVACIONES\n";

                double totalComisiones = 0.0;

                for (int i = 1; i <= rowCount; ++i) { // Empezamos desde 1 para saltar la fila de encabezados
                    int vendedor = sheet1->readNum(i, 0); // Suponiendo que el número de vendedor está en la columna 0
                    std::string nombre = sheet1->readStr(i, 1); // Suponiendo que el nombre está en la columna 1
                    int rubro = sheet1->readNum(i, 2); // Suponiendo que el rubro está en la columna 2
                    double montoVendido = sheet1->readNum(i, 3); // Suponiendo que el monto vendido está en la columna 3

                    double comision = 0.0;
                    // Realizar cálculos de comisión según el rubro
                    if (rubro == 1) {
                        comision = montoVendido * valor_comision_rubro_1; // Reemplazar valor_comision_rubro_1 con la comisión correspondiente
                    } else if (rubro == 2) {
                        comision = montoVendido * valor_comision_rubro_2; // Reemplazar valor_comision_rubro_2 con la comisión correspondiente
                    } else if (rubro == 3) {
                        comision = montoVendido * valor_comision_rubro_3; // Reemplazar valor_comision_rubro_3 con la comisión correspondiente
                    }

                    totalComisiones += comision;

                    std::cout << vendedor << " " << nombre << " " << std::fixed << std::setprecision(2) << comision;
                    if (montoVendido == 0) {
                        std::cout << " *\n";
                    } else {
                        std::cout << "\n";
                    }
                }

                std::cout << "TOTAL GENERAL DE COMISIONES: " << std::fixed << std::setprecision(2) << totalComisiones << "\n";

                book->release();
                return 0;
            }
        }
        book->release();
    }

    std::cerr << "Error al abrir el archivo Excel.\n";
    return -1;
}
