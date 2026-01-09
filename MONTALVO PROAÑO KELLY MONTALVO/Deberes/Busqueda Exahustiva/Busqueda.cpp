#include <iostream>
#include <fstream>
using namespace std;

bool esValida(int S, int E, int B)
{
    if (S + E + B != 14) return false;
    if (40 * S + 70 * E + 100 * B != 1000) return false;
    if (B < 2) return false;
    if (S < E) return false;
    return true;
}

int main()
{
    ofstream archivo;

    archivo.open("datos_energia.csv");

    if (!archivo.is_open())
    {
        cout << "ERROR: No se pudo crear el archivo" << endl;
        return 1;
    }

    archivo << "Intento,S,E,B,Valida\n";

    int intento = 0;
    int soluciones = 0;

    for (int S = 0; S <= 14; S++)
    {
        for (int E = 0; E <= 14; E++)
        {
            for (int B = 0; B <= 14; B++)
            {
                intento++;
                bool valida = esValida(S, E, B);

                archivo << intento << "," << S << "," << E << "," << B << "," << valida << "\n";

                if (valida)
                    soluciones++;
            }
        }
    }

    archivo.close();

    cout << "ARCHIVO datos_energia.csv CREADO CORRECTAMENTE" << endl;
    cout << "Total de soluciones validas: " << soluciones << endl;

    system("pause");
    return 0;
}
