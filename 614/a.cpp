#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long l, r, k, q = 1ll, lim = (long long) 1e18;
  vector<long long> v;
  cin >> l >> r >> k;
  while (true) {
    if (l <= q && q <= r) {
      v.push_back(q);
    }
    if (q > lim / k) {
      break;
    }
    q *= k;
  }
  if (v.empty()) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0, n = int(v.size()); i < n; ++i) {
    if (i > 0) {
      cout << ' ';
    }
    cout << v[i];
  }
  cout << endl;
  return 0;
}
