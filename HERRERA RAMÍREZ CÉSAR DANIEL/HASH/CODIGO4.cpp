#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<long long, int> hashFrecuencia;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        hashFrecuencia[x]++;
    }

    for (auto &par : hashFrecuencia) {
        cout << "Valor: " << par.first << "  Frecuencia: " << par.second << "\n";
    }

    return 0;
}
