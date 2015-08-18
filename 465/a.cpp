#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, ans = 0;
  string s;
  cin >> n >> s;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if ( ! ok) {
      break;
    }
    ++ans;
    ok = s[i] == '1';
  }
  cout << ans << endl;
  return 0;
}
