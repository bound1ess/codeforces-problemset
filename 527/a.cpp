#include <iostream>
#include <utility>

using namespace std;

int main() {
    long long ans = 0, a, b;
    cin >> a >> b;

    while (b > 0) {
        ans += a / b;
        a %= b;

        swap(a, b);
    }

    cout << ans << endl;

    return 0;
}
