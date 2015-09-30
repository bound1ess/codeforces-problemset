#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 2;
int a[N], l[N], r[N];

int main() {
  int n, k, x;
  cin >> n >> k >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    l[i] = l[i - 1] | a[i];
  }
  for (int i = n; i >= 1; --i) {
    r[i] = r[i + 1] | a[i];
  }
  long long ans = 0ll, tmp;
  for (int i = 1; i <= n; ++i) {
    tmp = a[i];
    for (int j = 0; j < k; ++j) {
      tmp *= x;
    }
    ans = max(ans, l[i - 1] | tmp | r[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
