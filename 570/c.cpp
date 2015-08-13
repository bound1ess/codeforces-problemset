#include <iostream>
#include <string>

using namespace std;

inline int calculate_f(string &s, int n) {
  int f = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') {
      int len = 1;
      for (int j = i + 1; j < n && s[j] == '.'; ++j) {
        ++len;
      }
      f += len - 1;
      i += len - 1;
    }
  }
  return f;
}

inline bool check_left(string &s, int pos) {
  return 0 < pos && s[pos - 1] == '.';
}

inline bool check_right(string &s, int pos, int n) {
  return pos + 1 < n && s[pos + 1] == '.';
}

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int f = calculate_f(s, n);
  for (int i = 0; i < m; ++i) {
    int x;
    char c;
    cin >> x >> c;
    --x;
    if (s[x] == '.' && c != '.') {
      if (check_left(s, x) && check_right(s, x, n)) {
        f -= 2;
      } else if (check_left(s, x) || check_right(s, x, n)) {
        --f;
      }
    } else if (s[x] != '.' && c == '.') {
      if (check_left(s, x) && check_right(s, x, n)) {
        f += 2;
      } else if (check_left(s, x) || check_right(s, x, n)) {
        ++f;
      }
    }
    s[x] = c;
    cout << f << endl;
  }
  return 0;
}
