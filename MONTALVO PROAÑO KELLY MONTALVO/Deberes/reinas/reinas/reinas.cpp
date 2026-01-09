#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>

// Constantes globales
const int TAMANIO = 8;
const int FACTORIAL_8 = 40320;

// Variables globales para almacenar soluciones
int* solucionesGlobales = nullptr;
int totalSoluciones = 0;
int procesoActual = 0;
int solucionSeleccionada = 0;
int solucionActual = 0;
std::ofstream archivoLog;

// Función para inicializar la memoria dinámicamente
int* crearTablero(int tamanio) {
    return new int[tamanio * tamanio];
}

// Función para liberar memoria
void liberarTablero(int* tablero) {
    delete[] tablero;
}

// Función para imprimir el tablero en consola (estilo ajedrez)
void imprimirTableroConsola(int* tablero, int tamanio) {
    std::cout << "\n    a   b   c   d   e   f   g   h\n";
    std::cout << "  +---+---+---+---+---+---+---+---+\n";
    for (int i = 0; i < tamanio; i++) {
        std::cout << (8-i) << " |";
        for (int j = 0; j < tamanio; j++) {
            int posicion = i * tamanio + j;
            // Alternar colores del tablero de ajedrez
            int esBlancoAjedrez = (i + j) % 2;
            
            if (*(tablero + posicion) == 1) {
                std::cout << " Q ";  // Reina
            } else if (esBlancoAjedrez) {
                std::cout << "   ";  // Cuadro blanco
            } else {
                std::cout << "   ";  // Cuadro negro
            }
            std::cout << "|";
        }
        std::cout << " " << (8-i) << "\n";
        std::cout << "  +---+---+---+---+---+---+---+---+\n";
    }
    std::cout << "    a   b   c   d   e   f   g   h\n";
    std::cout << std::flush;  // Forzar salida inmediata
}

// Función para imprimir en archivo
void imprimirEnArchivo(int* tablero, int tamanio, int numSolucion, int procesoDonde) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            int posicion = i * tamanio + j;
            archivoLog << (*(tablero + posicion) == 1 ? "Q " : ". ");
        }
        archivoLog << "\n";
    }
    archivoLog << "Solución #" << numSolucion << " encontrada en proceso: " << procesoDonde << "\n";
    archivoLog << "========================================\n\n";
}

// Función para verificar si una reina es atacada
int esSeguro(int* tablero, int fila, int columna, int tamanio) {
    // Verificar columna hacia arriba
    for (int i = 0; i < fila; i++) {
        int posicion = i * tamanio + columna;
        if (*(tablero + posicion) == 1) return 0;
    }

    // Verificar diagonal izquierda-arriba
    int i = fila, j = columna;
    while (i >= 0 && j >= 0) {
        int posicion = i * tamanio + j;
        if (*(tablero + posicion) == 1) return 0;
        i--;
        j--;
    }

    // Verificar diagonal derecha-arriba
    i = fila;
    j = columna;
    while (i >= 0 && j < tamanio) {
        int posicion = i * tamanio + j;
        if (*(tablero + posicion) == 1) return 0;
        i--;
        j++;
    }

    return 1;
}

// Función para limpiar una fila
void limpiarFila(int* tablero, int fila, int tamanio) {
    for (int j = 0; j < tamanio; j++) {
        int posicion = fila * tamanio + j;
        *(tablero + posicion) = 0;
    }
}

// Función backtracking para resolver las 8 reinas (TODAS las soluciones)
void resolverReinas(int* tablero, int fila, int tamanio) {
    procesoActual++;

    // Si todas las reinas están colocadas
    if (fila == tamanio) {
        totalSoluciones++;
        
        // Mostrar búsqueda en tiempo real
        if (totalSoluciones == solucionSeleccionada) {
            std::cout << "\n╔════════════════════════════════════════════════════════════════╗\n";
            std::cout << "║                 ✓ SOLUCIÓN SELECCIONADA ✓                      ║\n";
            std::cout << "╚════════════════════════════════════════════════════════════════╝\n";
            std::cout << "\nSolución #" << totalSoluciones << " ✓ SÍ\n";
            std::cout << "Encontrada en: PROCESO #" << procesoActual << "\n";
            std::cout << "Total de procesos hasta esta solución: " << procesoActual << "\n";
            imprimirTableroConsola(tablero, tamanio);
            imprimirEnArchivo(tablero, tamanio, totalSoluciones, procesoActual);
            
            // DETENER después de mostrar la solución seleccionada
            exit(0);
        } else {
            std::cout << "Solución " << totalSoluciones << " ✗ NO\n";
            std::cout << std::flush;  // Forzar salida inmediata
            imprimirTableroConsola(tablero, tamanio);
        }
        return;
    }

    // Intentar colocar reina en cada columna de la fila actual
    for (int columna = 0; columna < tamanio; columna++) {
        if (esSeguro(tablero, fila, columna, tamanio)) {
            int posicion = fila * tamanio + columna;
            *(tablero + posicion) = 1;

            // Log del intento
            archivoLog << "Proceso #" << procesoActual << ": Reina colocada en [" 
                      << fila << "," << columna << "]\n";

            resolverReinas(tablero, fila + 1, tamanio);

            // Backtrack - descolocar reina
            *(tablero + posicion) = 0;
        }
    }
}

// Función para mostrar estadísticas
void mostrarEstadisticas() {
    std::cout << "\n\n╔════════════════════════════════════════╗\n";
    std::cout << "║   ANÁLISIS DE COMPLEJIDAD ALGORITMICA   ║\n";
    std::cout << "╚════════════════════════════════════════╝\n\n";
    
    std::cout << "PROBLEMA: Las 8 Reinas\n";
    std::cout << "ALGORITMO: Backtracking (Fuerza Bruta Exhaustiva)\n\n";
    
    std::cout << "COMPLEJIDAD TIME (Temporal):\n";
    std::cout << "  • Peor caso: O(N!) = O(8!) = 40,320 operaciones\n";
    std::cout << "  • Razón: Se exploran todas las permutaciones posibles\n";
    std::cout << "  • Para cada fila, probamos hasta N columnas\n";
    std::cout << "  • Profundidad de recursión: N = 8\n";
    std::cout << "  • Fórmula: T(n) = n * T(n-1) = n!\n\n";
    
    std::cout << "COMPLEJIDAD SPACE (Espacio):\n";
    std::cout << "  • Memoria tablero: O(N²) = O(64) espacios\n";
    std::cout << "  • Pila de recursión: O(N) = O(8) llamadas\n";
    std::cout << "  • Espacio total: O(N²) + O(N) = O(N²)\n\n";
    
    std::cout << "CARACTERÍSTICAS:\n";
    std::cout << "  • Tipo: Algoritmo exhaustivo/de fuerza bruta\n";
    std::cout << "  • Técnica: Backtracking con poda\n";
    std::cout << "  • Soluciones encontradas: " << totalSoluciones << " de 92 posibles\n";
    std::cout << "  • Procesos ejecutados: " << procesoActual << "\n";
    std::cout << "  • Eficiencia: Con poda se reduce O(N!) dramáticamente\n\n";
    
    archivoLog << "\n\n╔════════════════════════════════════════╗\n";
    archivoLog << "║   ANÁLISIS DE COMPLEJIDAD ALGORITMICA   ║\n";
    archivoLog << "╚════════════════════════════════════════╝\n\n";
    archivoLog << "COMPLEJIDAD TEMPORAL: O(N!) = O(8!) = 40,320\n";
    archivoLog << "COMPLEJIDAD ESPACIAL: O(N²) + O(N) = O(64) + O(8)\n";
    archivoLog << "SOLUCIONES ENCONTRADAS: " << totalSoluciones << "/92\n";
    archivoLog << "SOLUCIÓN MOSTRADA: #" << solucionSeleccionada << "\n";
    archivoLog << "TOTAL DE PROCESOS: " << procesoActual << "\n";
    archivoLog << "FACTORIAL 8! = " << FACTORIAL_8 << " (No se repite)\n";
}

int main() {
    // Generar número aleatorio entre 1 y 92
    srand(time(NULL));
    solucionSeleccionada = (rand() % 92) + 1;  // Rango: 1-92

    std::cout << "╔════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║            PROBLEMA DE LAS 8 REINAS - BACKTRACKING            ║\n";
    std::cout << "║            (TODAS LAS SOLUCIONES - SELECCIÓN ALEATORIA)        ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════╝\n\n";
    
    std::cout << "Factorial de 8! = " << FACTORIAL_8 << " posibilidades\n";
    std::cout << "Soluciones válidas encontradas: 92\n";
    std::cout << "Solución aleatoria seleccionada: #" << solucionSeleccionada << "\n\n";
    std::cout << "Buscando todas las soluciones...\n";
    std::cout << "─────────────────────────────────\n\n";

    // Crear archivo de salida
    archivoLog.open("soluciones_8_reinas.txt", std::ios::app);
    
    if (!archivoLog.is_open()) {
        std::cerr << "Error al abrir el archivo de salida\n";
        return 1;
    }

    // Registrar inicio
    time_t ahora = time(nullptr);
    archivoLog << "═════════════════════════════════════════════════════════════════\n";
    archivoLog << "EJECUCIÓN DEL PROGRAMA - LAS 8 REINAS (SOLUCIÓN ALEATORIA)\n";
    archivoLog << "Fecha/Hora: " << ctime(&ahora);
    archivoLog << "Solución seleccionada aleatoriamente: #" << solucionSeleccionada << "\n";
    archivoLog << "Factorial 8! = " << FACTORIAL_8 << "\n";
    archivoLog << "═════════════════════════════════════════════════════════════════\n\n";

    // Crear tablero
    int* tablero = crearTablero(TAMANIO * TAMANIO);
    
    // Inicializar tablero a vacío
    for (int i = 0; i < TAMANIO * TAMANIO; i++) {
        *(tablero + i) = 0;
    }

    // Resolver el problema
    archivoLog << "PROCESO DE RESOLUCIÓN:\n";
    archivoLog << "─────────────────────────────────────────────────────────────────\n";
    resolverReinas(tablero, 0, TAMANIO);

    // Mostrar estadísticas
    mostrarEstadisticas();

    // Cerrar archivo
    archivoLog.close();

    // Liberar memoria
    liberarTablero(tablero);

    std::cout << "\n✓ Archivo 'soluciones_8_reinas.txt' creado exitosamente\n";
    std::cout << "✓ Total de soluciones: " << totalSoluciones << "\n";
    std::cout << "✓ Solución mostrada: #" << solucionSeleccionada << "\n";

    return 0;
}
