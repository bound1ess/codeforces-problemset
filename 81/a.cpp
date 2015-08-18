#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, ans;
  cin >> s;

  for (int i = 0, n = s.length(); i < n; ++i) {
    if (ans.length() > 0u && ans[ans.length() - 1] == s[i]) {
      ans.erase(ans.length() - 1, 1);
    } else {
      ans += s[i];
    }
  }

  cout << ans << endl;
  return 0;
}
