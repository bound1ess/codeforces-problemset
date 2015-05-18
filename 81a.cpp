#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    string ans;

    for (int i = 0; i < (int)str.length(); i++) {
        if ((int)ans.length() > 0 && ans[ans.length() - 1] == str[i]) {
            ans.erase(ans.length() - 1, 1);
        } else {
            ans += str[i];
        }
    }

    cout << ans << endl;

    return 0;
}
