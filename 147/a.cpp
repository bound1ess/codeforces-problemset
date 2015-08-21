#include <iostream>
#include <string>

using namespace std;

bool inline is_letter(char chr) {
  return 'a' <= chr && chr <= 'z';
}

int main() {
  string src, dest, ans;
  getline(cin, src);

  for (int i = 0, n = src.length(); i < n; ++i) {
    if (src[i] == ' ') {
      if (dest.empty() || dest[dest.length() - 1u] == src[i]) {
        continue;
      }
    }

    dest += src[i];
  }

  for (int i = 0, n = dest.length(); i < n; ++i) {
    if (dest[i] == ' ' && ! is_letter(dest[i + 1])) {
      continue;
    }

    ans += dest[i];

    if (dest[i] != ' ' && ! is_letter(dest[i]) && dest[i + 1] != ' ') {
      ans += ' ';
    }
  }

  cout << ans << endl;
  return 0;
}
