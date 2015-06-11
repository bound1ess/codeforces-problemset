#include <string>
#include <iostream>

using namespace std;

bool inline is_letter(char chr)
{
    return 'a' <= chr && chr <= 'z';
}

int main()
{
    string src, dest, ans;
    getline(cin, src);

    int length = src.length();

    for (int i = 0; i < length; i++) {
        if (src[i] == ' ') {
            if (dest.empty() || dest[(int) dest.length() - 1] == src[i]) {
                continue;
            }
        }

        dest += src[i];
    }

    length = dest.length();

    for (int i = 0; i < length; i++) {
        if (dest[i] == ' ' && ! is_letter(dest[i + 1])) {
            continue;
        }

        ans += dest[i];

        if (dest[i] != ' ' && ! is_letter(dest[i]) && dest[i + 1] != ' ') {
            ans += ' ';
        }
    }

    cout << ans << endl;

    return 0;
}
