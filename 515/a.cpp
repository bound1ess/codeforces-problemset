#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long a, b, s, path;
    cin >> a >> b >> s;

    path = abs(a) + abs(b);

    cout << (path <= s && (s - path) % 2 == 0 ? "Yes" : "No") << endl;

    return 0;
}
