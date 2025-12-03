
#include <iostream>
#include <algorithm> // Para max y max_element

using namespace std;

// Función que verifica y encuentra la carga mínima máxima
long long obtenerMayorTrabajo(long long* carpetas, int n, int trabajadores) {
    
    // 1. Definir límites (Low y High)
    long long bajo = 0;
    long long alto = 0;

    // 'bajo' debe ser al menos el tamaño del archivo más grande
    for (int i = 0; i < n; i++) {
        bajo = max(bajo, carpetas[i]);
        alto += carpetas[i]; // 'alto' es la suma total
    }

    // 2. Búsqueda Binaria 
    while (bajo < alto) {
        long long x = bajo + (alto - bajo) / 2; 

        int requeridos = 1;       // Empezamos con 1 trabajador
        long long cargaActual = 0;
        
        for (int i = 0; i < n; ++i) {
            // Si al trabajador actual le cabe la siguiente carpeta...
            if (cargaActual + carpetas[i] <= x) {
                cargaActual += carpetas[i];
            } else {
                // Si no le cabe, asignamos nuevo trabajador
                requeridos++;
                cargaActual = carpetas[i]; 
            }
        }

        if (requeridos <= trabajadores) {
            // Si pudimos hacerlo con los trabajadores disponibles (o menos),
            // significa que 'x' es factible. Intentamos buscar un 'x' menor.
            alto = x;
        } else {
            // Si necesitamos más trabajadores de los que tenemos,
            // 'x' es muy pequeño. Necesitamos aumentar la capacidad.
            bajo = x + 1;
        }
    }

    return bajo;
}

int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; // n = carpetas, k = trabajadores
   
    if (!(cin >> n >> k)) return 0;

    // Memoria dinámica
    long long* carpetas = new long long[n];

    for (int i = 0; i < n; ++i) {
        cin >> carpetas[i];
    }

    cout << obtenerMayorTrabajo(carpetas, n, k) << endl;

    delete[] carpetas;

    return 0;
}