#include <string>
#include <iostream>

using namespace std;

inline bool match(const string &s, const string &t, int off) {
  if (int(t.length()) - off < int(s.length())) {
    return false;
  }
  for (int i = 0, n = int(s.length()); i < n; ++i) {
    if (s[i] != t[off + i]) {
      return false;
    }
  }
  return true;
}

int main() {
  string s, a = "144", b = "14", c = "1";
  cin >> s;
  int len = int(s.length()), off = 0;
  while (0 < len) {
    if (match(a, s, off)) {
      len -= int(a.length());
      off += int(a.length());
      continue;
    }
    if (match(b, s, off)) {
      len -= int(b.length());
      off += int(b.length());
      continue;
    }
    if (match(c, s, off)) {
      len -= int(c.length());
      off += int(c.length());
    } else {
      break;
    }
  }
  cout << (0 == len ? "YES" : "NO") << endl;
  return 0;
}
