#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Variables globales
char** diccionarioCombinaciones = NULL;  // Arreglo de combinaciones
int totalCombinaciones = 0;
char* passwordVolatil = NULL;             // Almacena la contrasena volatil (4 digitos)

void limpiarPantalla() {
    system("cls");
}

void linea(int longitud = 50) {
    for (int i = 0; i < longitud; i++) cout << "=";
    cout << endl;
}

// Funcion para generar permutaciones (algoritmo voraz)
void generarPermutaciones(char* base, int inicio, int fin, char** diccionario, int& indice) {
    if (inicio == fin) {
        // Copiar la permutacion actual al diccionario
        *(diccionario + indice) = new char[5];
        char* destino = *(diccionario + indice);
        for (int i = 0; i < 4; i++) {
            *(destino + i) = *(base + i);
        }
        *(destino + 4) = '\0';
        indice++;
        return;
    }
    
    for (int i = inicio; i <= fin; i++) {
        // Intercambiar
        char temp = *(base + inicio);
        *(base + inicio) = *(base + i);
        *(base + i) = temp;
        
        // Recursion
        generarPermutaciones(base, inicio + 1, fin, diccionario, indice);
        
        // Intercambiar de nuevo (backtracking)
        temp = *(base + inicio);
        *(base + inicio) = *(base + i);
        *(base + i) = temp;
    }
}

// Crear el diccionario con todas las combinaciones de 4 numeros
void crearDiccionario() {
    // Para 4 digitos distintos: 4! = 24 permutaciones
    totalCombinaciones = 24;
    diccionarioCombinaciones = new char*[totalCombinaciones];
    
    char* combinacionBase = new char[5];
    *(combinacionBase + 0) = '1';
    *(combinacionBase + 1) = '2';
    *(combinacionBase + 2) = '3';
    *(combinacionBase + 3) = '4';
    *(combinacionBase + 4) = '\0';
    
    int indice = 0;
    
    generarPermutaciones(combinacionBase, 0, 3, diccionarioCombinaciones, indice);
    
    delete[] combinacionBase;
}

// Mostrar todas las combinaciones del diccionario
void mostrarDiccionario() {
    limpiarPantalla();
    linea(70);
    cout << "                      DICCIONARIO DE COMBINACIONES" << endl;
    cout << "                    (24 PERMUTACIONES DE 1234)" << endl;
    linea(70);
    
    cout << "\n[TODAS LAS CLAVES POSIBLES]:\n" << endl;
    
    for (int i = 0; i < totalCombinaciones; i++) {
        cout << "  [" << (i + 1) << "] " << *(diccionarioCombinaciones + i);
        if ((i + 1) % 4 == 0) {
            cout << endl;
        } else {
            cout << "    ";
        }
    }
    
    cout << "\n" << endl;
    linea(70);
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
}

// Generar contrasena volatil aleatoria
void generarPasswordVolatil() {
    srand(time(NULL) + totalCombinaciones);
    int randomIndex = rand() % totalCombinaciones;
    
    // Copiar la combinacion aleatoria a passwordVolatil
    if (passwordVolatil != NULL) {
        delete[] passwordVolatil;
    }
    
    passwordVolatil = new char[5];
    char* origen = *(diccionarioCombinaciones + randomIndex);
    for (int i = 0; i < 4; i++) {
        *(passwordVolatil + i) = *(origen + i);
    }
    *(passwordVolatil + 4) = '\0';
    
    // Mostrar cual fue seleccionada
    limpiarPantalla();
    linea(60);
    cout << "     *** CONTRASENA VOLATIL GENERADA EXITOSAMENTE ***" << endl;
    linea(60);
    cout << "\n[INFORMACION]" << endl;
    cout << "  Nueva contrasena seleccionada: " << passwordVolatil << endl;
    cout << "  Posicion en diccionario: " << (randomIndex + 1) << " de " << totalCombinaciones << endl;
    cout << "  Estado: ACTIVA" << endl;
    cout << "\n  Esta contrasena se usara para la proxima busqueda." << endl;
    linea(60);
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
}

// Algoritmo voraz para encontrar la contrasena
int buscarPasswordVoraz(char* passwordEncontrada) {
    int intentos = 0;
    
    cout << "\n[*] Iniciando busqueda voraz..." << endl;
    cout << "[*] Rastreando diccionario de " << totalCombinaciones << " combinaciones..." << endl << endl;
    
    for (int i = 0; i < totalCombinaciones; i++) {
        intentos++;
        
        // Mostrar cada 3 intentos
        if (intentos % 3 == 0) {
            cout << "  [Intento " << intentos << "] Probando: " << *(diccionarioCombinaciones + i) << endl;
        }
        
        // Comparar caracter por caracter (algoritmo voraz)
        bool coincide = true;
        char* combinacionActual = *(diccionarioCombinaciones + i);
        for (int j = 0; j < 4; j++) {
            if (*(combinacionActual + j) != *(passwordVolatil + j)) {
                coincide = false;
                break;
            }
        }
        
        if (coincide) {
            // Copiar la contraseña encontrada
            for (int j = 0; j < 4; j++) {
                *(passwordEncontrada + j) = *(combinacionActual + j);
            }
            *(passwordEncontrada + 4) = '\0';
            return intentos;
        }
    }
    
    return -1;  // No encontrada
}

void mostrarEstadisticas() {
    limpiarPantalla();
    linea(60);
    cout << "                    ESTADISTICAS DEL SISTEMA" << endl;
    linea(60);
    
    cout << "\n[DICCIONARIO]" << endl;
    cout << "  Combinaciones cargadas: " << totalCombinaciones << endl;
    cout << "  Tipo: Permutaciones de 4 digitos" << endl;
    
    cout << "\n[CONTRASENA VOLATIL]" << endl;
    cout << "  Estado: Generada (Aleatoria)" << endl;
    cout << "  Valor actual: [OCULTO]" << endl;
    
    cout << "\n[SISTEMA]" << endl;
    cout << "  Listo - Esperando ordenes" << endl;
    
    linea(60);
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
}

bool validarUsuario(char* usuario) {
    char* usuario_valido = new char[6];
    *(usuario_valido + 0) = 'a';
    *(usuario_valido + 1) = 'd';
    *(usuario_valido + 2) = 'm';
    *(usuario_valido + 3) = 'i';
    *(usuario_valido + 4) = 'n';
    *(usuario_valido + 5) = '\0';
    
    bool resultado = true;
    for (int i = 0; i < 6; i++) {
        if (*(usuario + i) != *(usuario_valido + i)) {
            resultado = false;
            break;
        }
    }
    
    delete[] usuario_valido;
    return resultado;
}

void liberarDiccionario() {
    if (diccionarioCombinaciones != NULL) {
        for (int i = 0; i < totalCombinaciones; i++) {
            delete[] *(diccionarioCombinaciones + i);
        }
        delete[] diccionarioCombinaciones;
        diccionarioCombinaciones = NULL;
    }
    
    if (passwordVolatil != NULL) {
        delete[] passwordVolatil;
        passwordVolatil = NULL;
    }
}

void romperCandadoVoraz(bool mostrarDetalles = true) {
    limpiarPantalla();
    linea(60);
    cout << "              INICIANDO ATAQUE VORAZ DE FUERZA BRUTA" << endl;
    linea(60);

    cout << "\n[PREPARACION]" << endl;
    cout << "  Diccionario de combinaciones: " << totalCombinaciones << " permutaciones" << endl;
    cout << "  Base: 1234 (permutaciones de 4 digitos)" << endl;

    cout << "\n[ATAQUE VORAZ]" << endl;
    cout << "  Metodo: Rastreo secuencial (1 a N)" << endl;
    cout << "  Objetivo: [OCULTA - Contrasena Volatil]" << endl;
    
    if (mostrarDetalles) {
        cout << "  Modo: DETALLADO (cada 3 intentos)\n" << endl;
    } else {
        cout << "  Modo: SILENCIOSO\n" << endl;
    }

    time_t tiempoInicio = time(NULL);
    char* passwordEncontrada = new char[5];
    int intentosFueron = buscarPasswordVoraz(passwordEncontrada);
    time_t tiempoFin = time(NULL);

    cout << "\n";
    linea(60);

    if (intentosFueron != -1) {
        cout << "      ++ CANDADO DESBLOQUEADO EXITOSAMENTE ++" << endl;
        linea(60);
        cout << "\n[RESULTADOS]" << endl;
        cout << "  Contrasena encontrada: " << passwordEncontrada << endl;
        cout << "  Intentos realizados: " << intentosFueron << " de " << totalCombinaciones << endl;
        cout << "  Tiempo transcurrido: " << (tiempoFin - tiempoInicio) << " segundo(s)" << endl;
        cout << "  Eficiencia: " << ((float)intentosFueron / totalCombinaciones * 100) << "%" << endl;
    } else {
        cout << "       -- CANDADO NO ABIERTO - CONTRASENA NO ENCONTRADA --" << endl;
        linea(60);
        cout << "\n[RESULTADOS]" << endl;
        cout << "  Se probaron: " << totalCombinaciones << " combinaciones" << endl;
        cout << "  Tiempo transcurrido: " << (tiempoFin - tiempoInicio) << " segundo(s)" << endl;
    }
    
    linea(60);
    cout << endl;
    
    delete[] passwordEncontrada;
}

void mostrarMenuPrincipal() {
    limpiarPantalla();
    linea(60);
    cout << "        CANDADO INTELIGENTE - ALGORITMO VORAZ" << endl;
    cout << "      Ataque de Fuerza Bruta (Sin Vectores, Sin Struct)" << endl;
    linea(60);
    
    cout << "\n[MENU PRINCIPAL]\n" << endl;
    cout << "  1. Ver diccionario completo (24 claves)" << endl;
    cout << "  2. Generar nueva contrasena volatil" << endl;
    cout << "  3. Ejecutar ataque (DETALLADO)" << endl;
    cout << "  4. Ejecutar ataque (SILENCIOSO)" << endl;
    cout << "  5. Ver estadisticas del sistema" << endl;
    cout << "  6. Salir\n" << endl;
}

int main() {
    srand(time(NULL));

    limpiarPantalla();
    linea(60);
    cout << "            SISTEMA DE SEGURIDAD - CANDADO VORAZ" << endl;
    cout << "          Autenticacion automatica iniciada..." << endl;
    linea(60);

    char* usuario = new char[10];
    *(usuario + 0) = 'a';
    *(usuario + 1) = 'd';
    *(usuario + 2) = 'm';
    *(usuario + 3) = 'i';
    *(usuario + 4) = 'n';
    *(usuario + 5) = '\0';

    if (validarUsuario(usuario)) {
        cout << "\n[LOGIN EXITOSO]" << endl;
        cout << "  Usuario: " << usuario << endl;
        cout << "  Permisos: ADMINISTRADOR" << endl;
        
        cout << "\n[INICIALIZACION]" << endl;
        cout << "  Creando diccionario de permutaciones..." << endl;
        crearDiccionario();
        cout << "  [+] Diccionario creado: " << totalCombinaciones << " combinaciones" << endl;
        
        cout << "  Generando contrasena volatil..." << endl;
        generarPasswordVolatil();
        cout << "  [+] Contrasena volatil generada exitosamente!" << endl;
        
        cout << "  [+] Sistema listo para operaciones!" << endl;
        cout << "\nPresione ENTER para continuar...";
        cin.ignore();

        int opcion = 0;
        bool salir = false;
        while (!salir) {
            mostrarMenuPrincipal();
            cout << "Seleccione una opcion (1-6): ";
            
            if (!(cin >> opcion)) {
                cin.clear();
                cin.ignore(10000, '\n');
                opcion = 0;
            }
            cin.ignore();

            switch(opcion) {
                case 1: {
                    mostrarDiccionario();
                    break;
                }

                case 2: {
                    generarPasswordVolatil();
                    break;
                }

                case 3: {
                    romperCandadoVoraz(true);
                    cout << "Presione ENTER para continuar...";
                    cin.ignore();
                    break;
                }

                case 4: {
                    romperCandadoVoraz(false);
                    cout << "Presione ENTER para continuar...";
                    cin.ignore();
                    break;
                }

                case 5: {
                    mostrarEstadisticas();
                    break;
                }

                case 6: {
                    limpiarPantalla();
                    linea(60);
                    cout << "      Sistema cerrado. Diccionario liberado. Hasta luego." << endl;
                    linea(60);
                    cout << endl;
                    salir = true;
                    break;
                }

                default: {
                    cout << "\n[ERROR] Opcion invalida (1-6). Intente nuevamente.\n" << endl;
                    cout << "Presione ENTER para continuar...";
                    cin.ignore();
                }
            }
        }
    } else {
        cout << "\n[ACCESO DENEGADO] Usuario invalido." << endl;
    }

    delete[] usuario;
    liberarDiccionario();

    return 0;
}
