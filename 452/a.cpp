#include <iostream>
#include <string>

using namespace std;

const int N = 8;
const string s[N] = {
  "vaporeon", "jolteon", "flareon", "espeon",
  "umbreon", "leafeon", "glaceon", "sylveon",
};

inline bool check(const string &full, const string &dot, int n) {
  if (int(full.length()) != n) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    if (dot[i] != '.' && dot[i] != full[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  string t;
  cin >> n >> t;
  for (int i = 0; i < N; ++i) {
    if (check(s[i], t, n)) {
      cout << s[i] << endl;
      break;
    }
  }
  return 0;
}
