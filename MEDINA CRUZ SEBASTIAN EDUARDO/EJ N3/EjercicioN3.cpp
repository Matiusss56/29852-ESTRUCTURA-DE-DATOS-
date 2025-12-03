#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int vol[200000];
    for (int i = 0; i < n; i++) cin >> vol[i];  

    int l = 0, r = 100, ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            int finalVol = vol[i];
            if (finalVol > mid) finalVol = mid; // filtro
            if (finalVol > 70) ok = false;
        }

        if (ok) {
            ans = mid;
            l = mid + 1;  // buscar un límite mayor
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
