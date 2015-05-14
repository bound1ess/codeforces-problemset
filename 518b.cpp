#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int const N = 26;
int s_chars[N * 2], t_chars[N * 2];

int get_index(const char& chr)
{
    return chr >= 'a' ? (chr - 'a') + N : (chr - 'A');
}

int main()
{
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < (int)s.size(); i++) {
        s_chars[get_index(s[i])]++;
    }

    for (int i = 0; i < (int)t.size(); i++) {
        t_chars[get_index(t[i])]++;
    }

    int a = 0, b = 0;

    for (int i = 0; i < N * 2; i++) {
        int val = min(s_chars[i], t_chars[i]);

        if (val < 1) {
            continue;
        }

        s_chars[i] -= val;
        t_chars[i] -= val;

        a += val;
    }

    //for (int i = 0; i < N; i++)
    //    cout << (char)(i + 65) << ": " << chars[i] << endl;
    //for (int i = 0; i < N; i++)
    //    cout << (char)(i + 97) << ": " << chars[i + N] << endl;

    for (int i = 0; i < N; i++) {
        int val = min(s_chars[i], t_chars[i + N]);

        if (val < 1) {
            continue;
        }

        s_chars[i] -= val;
        t_chars[i + N] -= val;

        b += val;
    }

    for (int i = N; i < 2 * N; i++) {
        int val = min(s_chars[i], t_chars[i - N]);

        if (val < 1) {
            continue;
        }

        s_chars[i] -= val;
        t_chars[i - N] -= val;

        b += val;
    }

    cout << a << " " << b << endl;

    return 0;
}
