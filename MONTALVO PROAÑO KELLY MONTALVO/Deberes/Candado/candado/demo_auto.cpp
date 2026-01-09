#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

struct Nodo {
    string dato;
    Nodo* siguiente;
};

Nodo* listaPasswordsGlobal = NULL;
string passwordVolatilGlobal = "";

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void limpiarPantalla() {
    system("cls");
}

void linea(int longitud = 50) {
    for (int i = 0; i < longitud; i++) cout << "=";
    cout << endl;
}

Nodo* crearNodo(string valor) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void agregarAlFinal(Nodo*& lista, string valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    
    if (lista == NULL) {
        lista = nuevoNodo;
        return;
    }
    
    Nodo* actual = lista;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevoNodo;
}

int contarElementos(Nodo* lista) {
    int contador = 0;
    Nodo* actual = lista;
    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

int buscarEnLista(Nodo* lista, string& passwordEncontrada) {
    Nodo* actual = lista;
    int intentos = 0;

    while (actual != NULL) {
        intentos++;
        
        if (intentos % 10 == 0) {
            setColor(11);
            cout << "  [Intento " << intentos << "] Probando: " << actual->dato;
            setColor(7);
            cout << endl;
        }

        if (actual->dato == passwordVolatilGlobal) {
            passwordEncontrada = actual->dato;
            return intentos;
        }
        actual = actual->siguiente;
    }
    return -1;
}

void generarPasswordVolatil() {
    ifstream archivo("diccionario.txt");
    string palabra;
    Nodo* listaTemp = NULL;

    if (!archivo.is_open()) {
        setColor(12);
        cout << "Error: No se pudo abrir diccionario.txt" << endl;
        setColor(7);
        return;
    }

    while (getline(archivo, palabra)) {
        if (!palabra.empty()) {
            agregarAlFinal(listaTemp, palabra);
        }
    }
    archivo.close();

    int totalPalabras = contarElementos(listaTemp);
    if (totalPalabras > 0) {
        int indiceAleatorio = rand() % totalPalabras;
        Nodo* actual = listaTemp;
        
        for (int i = 0; i < indiceAleatorio; i++) {
            actual = actual->siguiente;
        }
        
        passwordVolatilGlobal = actual->dato;
        setColor(10);
        cout << "  [+] Contraseña volátil generada exitosamente!" << endl;
        setColor(7);
    }

    // Liberar lista temporal
    Nodo* act = listaTemp;
    while (act != NULL) {
        Nodo* temp = act;
        act = act->siguiente;
        delete temp;
    }
}

void liberarLista(Nodo*& lista) {
    Nodo* actual = lista;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    lista = NULL;
}

void romperCandadoConLista() {
    ifstream archivo("diccionario.txt");
    string palabra;

    if (!archivo.is_open()) {
        setColor(12);
        cout << "Error al abrir el diccionario." << endl;
        setColor(7);
        return;
    }

    limpiarPantalla();
    setColor(10);
    linea(60);
    cout << "                 INICIANDO ATAQUE DE FUERZA BRUTA" << endl;
    linea(60);
    setColor(7);

    cout << "\n[PREPARACION]" << endl;
    cout << "  Cargando diccionario en lista enlazada..." << endl;
    
    while (getline(archivo, palabra)) {
        if (!palabra.empty()) {
            agregarAlFinal(listaPasswordsGlobal, palabra);
        }
    }
    archivo.close();

    int totalPalabras = contarElementos(listaPasswordsGlobal);
    setColor(10);
    cout << "  [+] Palabras cargadas: " << totalPalabras << endl;
    setColor(7);

    cout << "\n[ATAQUE]" << endl;
    cout << "  Estado: FUERZA BRUTA" << endl;
    cout << "  Objetivo: [OCULTA - Contraseña Volátil]" << endl;
    cout << "  Modo: AUTOMATICO\n" << endl;

    time_t tiempoInicio = time(NULL);
    string passwordEncontrada = "";
    int intentosFueron = buscarEnLista(listaPasswordsGlobal, passwordEncontrada);
    time_t tiempoFin = time(NULL);

    cout << "\n";
    linea(60);

    if (intentosFueron != -1) {
        setColor(10);
        cout << "       ¡¡ CANDADO ABIERTO EXITOSAMENTE !!" << endl;
        setColor(7);
        linea(60);
        cout << "\n[RESULTADOS]" << endl;
        setColor(10);
        cout << "  Contraseña encontrada: " << passwordEncontrada << endl;
        setColor(7);
        cout << "  Intentos realizados: " << intentosFueron << " de " << totalPalabras << endl;
        cout << "  Tiempo transcurrido: " << (tiempoFin - tiempoInicio) << " segundo(s)" << endl;
        cout << "  Eficiencia: " << ((float)intentosFueron / totalPalabras * 100) << "%" << endl;
    } else {
        setColor(12);
        cout << "       CANDADO NO ABIERTO - CONTRASEÑA NO ENCONTRADA" << endl;
        setColor(7);
        linea(60);
        cout << "\n[RESULTADOS]" << endl;
        cout << "  Se probaron: " << totalPalabras << " combinaciones" << endl;
    }
    
    linea(60);
    cout << endl;
}

int main() {
    srand(time(NULL));

    limpiarPantalla();
    setColor(10);
    linea(60);
    cout << "        DEMOSTRACION AUTOMATICA - PROGRAMA INTERACTIVO" << endl;
    cout << "           Algoritmo de Fuerza Bruta con Listas" << endl;
    linea(60);
    setColor(7);

    string usuario = "admin";

    if (usuario == "admin") {
        setColor(10);
        cout << "\n[LOGIN EXITOSO]" << endl;
        cout << "  Usuario: " << usuario << endl;
        cout << "  Permisos: ADMINISTRADOR" << endl;
        setColor(7);
        
        cout << "\n[INICIALIZACION]" << endl;
        cout << "  Generando contraseña volátil..." << endl;
        generarPasswordVolatil();
        
        cout << "  Diccionario listo para usar..." << endl;
        setColor(10);
        cout << "  [+] Sistema listo para operaciones!" << endl;
        setColor(7);

        cout << "\n[DEMOSTRACIÓN AUTOMÁTICA]" << endl;
        cout << "  Ejecutando ataque...\n" << endl;
        
        Sleep(2000);
        
        romperCandadoConLista();
        
        setColor(10);
        cout << "[CONCLUSIÓN]" << endl;
        setColor(7);
        cout << "  El programa interactivo incluye menú con 5 opciones:" << endl;
        cout << "  1. Generar nueva contraseña volátil" << endl;
        cout << "  2. Ejecutar ataque (DETALLADO)" << endl;
        cout << "  3. Ejecutar ataque (SILENCIOSO)" << endl;
        cout << "  4. Ver estadísticas del sistema" << endl;
        cout << "  5. Salir" << endl;
        cout << "\n  ¡Ejecuta candado.exe para acceso interactivo completo!" << endl;
    }

    liberarLista(listaPasswordsGlobal);

    return 0;
}
