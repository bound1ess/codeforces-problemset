#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3 * 1e5;
int a[N];

int main() {
  int n;
  long long ans = 0ll;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a, a + n);

  for (int i = 1; i <= n - 1; ++i) {
    ans += (i + 1) * 1ll * a[i - 1];
  }

  cout << (ans + n * 1ll * a[n - 1]) << endl;
  return 0;
}
