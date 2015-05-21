#include <iostream>

using namespace std;

int force[3] = {0, 0, 0};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n * 3; i++) {
        int value;
        cin >> value;

        force[i % 3] += value;
    }

    cout << ((force[0] || force[1] || force[2]) ? "NO" : "YES") << endl;

    return 0;
}
