#include <iostream>
#include <string>

using namespace std;

int main() {
  string ans, s;
  cin >> s;

  for (int i = 0, j = 0, n = s.length(); i < n; ++i) {
    if (s[i] == '/') {
      if (j == 0) {
        ans += '/';
        j = 1;
      }
    } else {
      ans += s[i];
      j = 0;
    }
  }

  if (ans[ans.length() - 1u] == '/' && ans != "/") {
    ans.resize(ans.length() - 1u);
  }

  cout << ans << endl;
  return 0;
}
