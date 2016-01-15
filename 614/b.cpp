#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, l, r, m, z = 0;
  string a, b, c;
  bool failed = false;
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    m = int(a.length());
    l = 0, r = m - 1;
    while (l < m && a[l] == '0') {
      ++l;
    }
    if (l == m) {
      failed = true;
      continue;
    }
    while (a[r] == '0') {
      --r, ++z;
    }
    b.clear();
    for (int j = l; j <= r; ++j) {
      b += a[j];
    }
    if (b == "1") {
      if (c.empty()) {
        c = "1";
      }
    } else {
      c = b;
    }
  }
  if (failed) {
    cout << 0 << endl;
  } else {
    cout << c;
    for (int i = 0; i < z; ++i) {
      cout << 0;
    }
    cout << endl;
  }
  return 0;
}
