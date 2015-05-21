#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    int b = 1, ans = 0;

    for (int i = 0; i < n; i++) {
        if (b == 1) {
            b = (int)(str[i] == '1');
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
