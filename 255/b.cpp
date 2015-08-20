#include <iostream>
#include <string>

using namespace std;

inline int _abs(int x) {
  return x < 0 ? -x : x;
}

int main() {
  string s, t;
  int x = 0;
  cin >> s;

  for (int i = 0, n = s.length(); i < n; ++i) {
    x += s[i] == 'x' ? 1 : -1;
  }

  for (int i = 0, j = _abs(x); i < j; ++i) {
    t += x > 0 ? 'x' : 'y';
  }

  cout << t << endl;
  return 0;
}
