#include <iostream>
#include <string>

using namespace std;

string m[299];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> m[i];

    char chr;

    for (int i = 0; i < n; i++) {
        if (i > 0 && m[i][i] != chr) {
            cout << "NO" << endl;
            return 0;
        }

        chr = m[i][i];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (chr != m[i][n - i - 1]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    int chrCnt = 0;
    chr = m[0][1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == chr)
                chrCnt++;
        }
    }

    cout << (((n * n) - (n + n - 1) - chrCnt) == 0 ? "YES" : "NO") << endl;

    return 0;
}
