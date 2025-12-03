#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    string apellido;
    string cedula;
    bool ocupado;
};

int TAM = 50;
Persona* tabla;   // <-- Puntero a arreglo dinámico de Personas

// --- Función hash ---
int hashCedula(string cedula) {
    int suma = 0;
    for (char c : cedula)
        suma += c;
    return suma % TAM;
}

// --- Insertar persona (solo punteros) ---
void insertar(string nombre, string apellido, string cedula) {
    int pos = hashCedula(cedula);

    // Manejo de colisiones (lineal)
    while ( (*(tabla + pos)).ocupado ) {
        pos = (pos + 1) % TAM;
    }

    (*(tabla + pos)).nombre = nombre;
    (*(tabla + pos)).apellido = apellido;
    (*(tabla + pos)).cedula = cedula;
    (*(tabla + pos)).ocupado = true;
}

// --- Buscar persona por cédula ---
int buscar(string cedula) {
    int pos = hashCedula(cedula);
    int intentos = 0;

    while ( (*(tabla + pos)).ocupado && intentos < TAM ) {
        if ( (*(tabla + pos)).cedula == cedula )
            return pos;

        pos = (pos + 1) % TAM;
        intentos++;
    }
    return -1;
}

int main() {
    // Crear memoria dinámicamente
    tabla = new Persona[TAM];

    // Inicializar tabla (sin [])
    for (int i = 0; i < TAM; i++) {
        (*(tabla + i)).ocupado = false;
    }

    int n;
    cout << "Cuantas personas quieres ingresar? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string nombre, apellido, cedula;

        cout << "\nPersona " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "Cedula: ";
        cin >> cedula;

        insertar(nombre, apellido, cedula);
    }

    // --- Buscar ---
    string cedBuscar;
    cout << "\nBuscar cedula: ";
    cin >> cedBuscar;

    int pos = buscar(cedBuscar);

    if (pos != -1) {
        cout << "\nENCONTRADO:\n";
        cout << "Nombre: " << (*(tabla + pos)).nombre << endl;
        cout << "Apellido: " << (*(tabla + pos)).apellido << endl;
        cout << "Cedula: " << (*(tabla + pos)).cedula << endl;
    } else {
        cout << "\nNo existe esa cedula.\n";
    }

    delete[] tabla; // liberar memoria
    return 0;
}
