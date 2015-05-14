#include <iostream>
#include <string>

using namespace std;

int chars[26] = {0};

int main()
{
    string str;
    cin >> str;

    while (str[str.size() - 1] != '}') {
        string substr;
        cin >> substr;

        str += substr;
    }

    for (int i = 1; i < (int)str.size() - 1; i++) {
        if (str[i] != ',') {
            chars[str[i] - 'a']++;
        }
    }

    int cnt = 0;

    for (int i = 0; i < 26; i++) {
        if (chars[i] > 0) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
