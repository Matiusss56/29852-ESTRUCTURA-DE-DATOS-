#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long tiendas[200000], almacenes[200000];

    for (int i = 0; i < n; i++)
        cin >> tiendas[i];
    for (int i = 0; i < m; i++)
        cin >> almacenes[i];

    // ----- ORDENAR TIENDAS (bubble sort) -----
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (tiendas[j] > tiendas[j + 1])
            {
                long long temp = tiendas[j];
                tiendas[j] = tiendas[j + 1];
                tiendas[j + 1] = temp;
            }
        }
    }

    // ----- ORDENAR ALMACENES (bubble sort) -----
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - 1 - i; j++)
        {
            if (almacenes[j] > almacenes[j + 1])
            {
                long long temp = almacenes[j];
                almacenes[j] = almacenes[j + 1];
                almacenes[j + 1] = temp;
            }
        }
    }

    long long l = 0, r = 2000000000000LL, ans = r;

    while (l <= r)
    {
        long long R = (l + r) / 2;
        bool ok = true;

        for (int i = 0; i < n; i++)
        {
            long long t = tiendas[i];

            long long distMin = 9000000000000000LL;

            for (int j = 0; j < m; j++)
            {
                long long d = t - almacenes[j];
                if (d < 0)
                    d = -d; 
                if (d < distMin)
                    distMin = d;
            }

            if (distMin > R)
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            ans = R;
            r = R - 1;
        }
        else
        {
            l = R + 1;
        }
    }

    cout << ans;
    return 0;
}