#include <iostream>
#include <string>

using namespace std;

const int N = 26;
bool chars[N];

int main() {
  string s;
  getline(cin, s);
  for (int i = 1, n = s.length(); i < n - 1; ++i) {
    if (s[i] != ',') {
      chars[s[i] - 'a'] = true;
    } else {
      ++i;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if (chars[i]) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
