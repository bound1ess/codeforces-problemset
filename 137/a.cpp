#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  int buf = 0, ans = 0;
  cin >> s;

  for (int i = 0, n = s.length(); i < n; ++i) {
    if (i == 0) {
      ++buf;
      continue;
    }

    if (s[i] == s[i - 1]) {
      ++buf;

      if (buf > 5) {
        ++ans, buf = 1;
      }
    } else {
      ++ans, buf = 1;
    }
  }

  if (buf > 0) {
    ++ans;
  }

  cout << ans << endl;
  return 0;
}
