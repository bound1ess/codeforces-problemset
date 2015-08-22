#include <iostream>
#include <string>

using namespace std;

int main() {
  int len = 1, ans = 0;
  char prev = 'Z';
  string code;
  cin >> code;

  for (int i = 0, n = code.length(); i < n; ++i) {
    if (code[i] == prev) {
      ++len;
    } else {
      if (len % 2 == 0) {
        ++ans;
      }

      len = 1;
    }

    prev = code[i];
  }

  if (len % 2 == 0) {
    ++ans;
  }

  cout << ans << endl;
  return 0;
}
