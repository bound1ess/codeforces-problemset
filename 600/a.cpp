#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

inline bool check(const string &s) {
  if (s.empty()) {
    return false;
  }
  for (int i = 0, n = (int) s.length(); i < n; ++i) {
    if ('0' <= s[i] && s[i] <= '9') {
      if (i == 0 && n > 1 && s[i] == '0') {
        return false;
      }
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  string s, t;
  vector<string> a, b;
  cin >> s;
  for (int i = 0, n = (int) s.length(); i < n; ++i) {
    if (s[i] == ';' || s[i] == ',') {
      (check(t) ? a : b).push_back(t);
      t.clear();
    } else {
      t += s[i];
    }
  }
  (check(t) ? a : b).push_back(t);
  if ( ! a.empty()) {
    putchar((char) 34);
    for (int i = 0, n = (int) a.size(); i < n; ++i) {
      if (i > 0) {
        putchar(',');
      }
      cout << a[i];
    }
    putchar((char) 34);
    putchar('\n');
  } else {
    puts("-");
  }
  if ( ! b.empty()) {
    putchar((char) 34);
    for (int i = 0, n = (int) b.size(); i < n; ++i) {
      if (i > 0) {
        putchar(',');
      }
      cout << b[i];
    }
    putchar((char) 34);
    putchar('\n');
  } else {
    puts("-");
  }
  return 0;
}
