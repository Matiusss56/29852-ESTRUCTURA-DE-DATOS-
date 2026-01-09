#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream archivo("datos_suma.csv");
    archivo << "Iteracion,SumaAcumulada\n";

    int suma = 0;

    for (int i = 1; i <= 30; i++) {
        int valor = i + (100 - i); // siempre 100
        suma += valor;

        archivo << i << "," << suma << "\n";

        cout << i << " + " << (100 - i) << " = " << valor << endl;
    }

    suma += 50; // número central
    archivo << 50 << "," << suma << "\n";

    cout << "Suma total: " << suma << endl;

    archivo.close();
    return 0;
}
