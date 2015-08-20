#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 100;
int a[N];

inline int parse(const string &s, int l, int r) {
  int ans = 0;

  for (int i = l; i <= r; ++i) {
    ans *= 10;
    ans += s[i] - '0';
  }

  return ans;
}

int main() {
  string s; cin >> s;
  int j = 0;

  for (int i = 0, n = s.length(); i < n; ++i) {
    if (s[i] == ',') {
      continue;
    }

    int l = i, r = i;

    for (int k = i + 1; k < n && s[k] != ','; ++k) {
      ++r;
    }

    a[j] = parse(s, l, r);
    ++j, i += r - l;
  }

  sort(a, a + j);

  for (int i = 0; i < j; ++i) {
    int k = 1, m = i;

    while (m + 1 < j && a[m + 1] - a[m] <= 1) {
      ++m, ++k;
    }

    if (k > 1 && a[i] != a[m]) {
      cout << a[i] << "-" << a[m];
    } else {
      cout << a[i];
    }

    i = m;

    if (m + 1 < j) {
      cout << ",";
    }
  }

  cout << endl;
  return 0;
}
