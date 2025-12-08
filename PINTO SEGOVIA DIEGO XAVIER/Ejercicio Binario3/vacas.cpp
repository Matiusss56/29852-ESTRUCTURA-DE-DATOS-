#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función que verifica si es posible colocar C vacas
// con una distancia mínima de minDist entre ellas
bool canPlaceCows(vector<long long>& stalls, int C, long long minDist) {
    int cowsPlaced = 1;  // Colocamos la primera vaca en el primer establo
    long long lastPosition = stalls[0];
    
    for (int i = 1; i < stalls.size(); i++) {
        // Si este establo está lo suficientemente lejos del último
        if (stalls[i] - lastPosition >= minDist) {
            cowsPlaced++;
            lastPosition = stalls[i];
            
            // Si ya colocamos todas las vacas
            if (cowsPlaced >= C) {
                return true;
            }
        }
    }
    
    return cowsPlaced >= C;
}

int main() {
    cout << "=== PROBLEMA: AGGRESSIVE COWS ===" << endl << endl;
    
    int N, C;
    cout << "Ingrese el numero de establos (N): ";
    cin >> N;
    
    cout << "Ingrese el numero de vacas (C): ";
    cin >> C;
    
    vector<long long> stalls(N);
    cout << "\nIngrese la posicion de cada establo:" << endl;
    
    for (int i = 0; i < N; i++) {
        cout << "Establo " << (i + 1) << ": ";
        cin >> stalls[i];
    }
    
    // Ordenar los establos por posición
    sort(stalls.begin(), stalls.end());
    
    cout << "\n--- Establos ordenados ---" << endl;
    cout << "Posiciones: ";
    for (int i = 0; i < N; i++) {
        cout << stalls[i];
        if (i < N - 1) cout << ", ";
    }
    cout << endl;
    cout << "Vacas a colocar: " << C << endl;
    
    // Búsqueda binaria sobre la distancia mínima
    long long left = 1;  // Distancia mínima posible
    long long right = stalls[N - 1] - stalls[0];  // Distancia máxima posible
    long long answer = 0;
    
    cout << "\n--- Busqueda Binaria sobre la Distancia Minima ---" << endl;
    cout << "Rango inicial: [" << left << ", " << right << "]" << endl << endl;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        cout << "Probando minDist = " << mid << "... ";
        
        if (canPlaceCows(stalls, C, mid)) {
            // Es posible con esta distancia, intentar con una mayor
            answer = mid;
            left = mid + 1;
            cout << "POSIBLE (buscando mayor)" << endl;
        } else {
            // No es posible, intentar con una distancia menor
            right = mid - 1;
            cout << "IMPOSIBLE (buscando menor)" << endl;
        }
    }
    
    cout << "\n=== RESULTADO ===" << endl;
    cout << "Maxima distancia minima: " << answer << endl;
    
    // Mostrar una colocación válida
    cout << "\n--- Ejemplo de colocacion ---" << endl;
    
    vector<long long> cowPositions;
    long long lastPos = stalls[0];
    cowPositions.push_back(lastPos);
    
    for (int i = 1; i < N && cowPositions.size() < C; i++) {
        if (stalls[i] - lastPos >= answer) {
            cowPositions.push_back(stalls[i]);
            lastPos = stalls[i];
        }
    }
    
    for (int i = 0; i < cowPositions.size(); i++) {
        cout << "Vaca " << (i + 1) << " en posicion: " << cowPositions[i] << endl;
    }
    
    cout << "\nDistancias entre vacas consecutivas:" << endl;
    for (int i = 1; i < cowPositions.size(); i++) {
        cout << "Vaca " << i << " <-> Vaca " << (i + 1) << ": " 
             << (cowPositions[i] - cowPositions[i - 1]) << " unidades" << endl;
    }
    
    cout << "\nDistancia minima garantizada: " << answer << " unidades" << endl;
    
    return 0;
}