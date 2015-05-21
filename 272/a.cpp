#include <iostream>

using namespace std;

int main()
{
    int n, f = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        f += tmp;
    }

    int ans = 0;

    for (int i = 1; i <= 5; i++) {
        if ((f + i) % (n + 1) != 1) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
