#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector <int> a;
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector <int> p;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      p.push_back(i);
    }
  }
  if (p.empty()) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 1LL;
  for (int i = 0, m = int(p.size()); i < m - 1; ++i) {
    ans *= (long long) p[i + 1] - p[i];
  }
  cout << ans << endl;
  return 0;
}
