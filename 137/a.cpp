#include <iostream>
#include <string>

using namespace std;

int main()
{
    string path; cin >> path;

    int buf = 0, ans = 0, len = path.length();

    for (int i = 0; i < len; i++) {
        if (i < 1) {
            buf++;
        } else if (path[i] == path[i - 1]) {
            buf++;

            if (buf > 5) {
                ans++, buf = 1;
            }
        } else {
            buf = 1, ans++;
        }
    }

    if (buf > 0) {
        ans++;
    }

    cout << ans << endl;

    return 0;
}
