#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string map[50];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> map[i];

    int l = m - 1, r = 0;
    int u = n - 1, d = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '.')
                continue;

            u = min(u, i);
            d = max(d, i);

            l = min(l, j);
            r = max(r, j);
        }
    }

    for (int i = u; i <= d; i++) {
        for (int j = l; j <= r; j++) {
            cout << map[i][j];
        }

        cout << endl;
    }

    return 0;
}
