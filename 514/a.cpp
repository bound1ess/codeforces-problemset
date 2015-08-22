#include <iostream>
#include <string>

using namespace std;

int main() {
  string s; cin >> s;

  for (int i = 0, n = s.length(); i < n; ++i) {
    if (s[i] == '9' && i < 1) {
      continue;
    }

    if (s[i] >= '5') {
      s[i] = '9' - (s[i] - '0');
    }
  }

  cout << s << endl;
  return 0;
}
