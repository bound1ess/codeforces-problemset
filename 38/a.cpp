#include <iostream>

using namespace std;

int d[101];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        cin >> d[i];

        if (i > 1)
            d[i] += d[i - 1];
    }

    int a, b;
    cin >> a >> b;

    cout << (d[b - 1] - d[a - 1]) << endl;

    return 0;
}
