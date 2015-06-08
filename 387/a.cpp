#include <iostream>
#include <string>

using namespace std;

int inline parse(const string& time)
{
    return (time[0] - '0') * 10 + (time[1] - '0');
}

int inline subtract(int a, int b, int c)
{
    return a - b < 0 ? (c + a - b) : a - b;
}

string inline format(int n)
{
    string result;

    if (n > 9) {
        result += (char) (48 + (n / 10));
    } else {
        result += '0';
    }

    result += (char) (48 + (n % 10));

    return result;
}

int main()
{
    string s, t;
    cin >> s >> t;

    string s_left = s.substr(0, 2), s_right = s.substr(3);
    string t_left = t.substr(0, 2), t_right = t.substr(3);

    //cout << s_left << " " << s_right << endl;
    //cout << format(subtract(parse(s_left), parse(t_left), 24)) << ":"
    //    << format(subtract(parse(s_right), parse(t_right), 60)) << endl;
    int left, right;

    left = subtract(parse(s_left), parse(t_left), 24);

    if (parse(s_right) - parse(t_right) < 0) {
        left = subtract(left, 1, 24);
    }

    right = subtract(parse(s_right), parse(t_right), 60);

    cout << format(left) << ":" << format(right) << endl;

    return 0;
}
