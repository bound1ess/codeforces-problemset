#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int q;
    cin >> q;

    map<string, string> m;

    for (int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;

        bool found = false;

        for (auto it = m.begin(); it != m.end(); it++) {
            //cout << "call" << endl;
            if (it->second == a) {
                it->second = b;
                found = true;

                break;
            }
        }

        if ( ! found) {
            //cout << "Inserting " << a << " as " << b << endl;
            m[a] = b;
        }
    }

    cout << m.size() << endl;

    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}
