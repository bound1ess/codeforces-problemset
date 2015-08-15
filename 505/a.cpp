#include <iostream>
#include <string>

using namespace std;

inline void restore(string &s) {
  for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
    if (s[i] == '?') {
      s[i] = s[j];
      break;
    }
    if (s[j] == '?') {
      s[j] = s[i];
      break;
    }
  }
}

inline bool is_palindrome(string &s) {
  for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) {
      return false;
    }
  }
  return true;
}

int main() {
  string s; cin >> s;
  for (int i = 0, n = s.length(); i <= n; ++i) {
    string copy = s;
    copy.insert(i, 1, '?');
    restore(copy);

    if (is_palindrome(copy)) {
      cout << copy << endl;
      return 0;
    }
  }
  cout << "NA" << endl;
  return 0;
}
