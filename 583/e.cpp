#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1234567;
int a[N], gcd[N], is_max[N], cnt[N];

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) {
      for (int j = i; j <= n; j += i) {
        gcd[j] = i;
      }
    }
  }
  long long ans = 0ll;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) {
      for (int j = 0; j < i; ++j) {
        int m = 0;
        for (int q = j; q < n; q += i) {
          m = max(m, a[q]);
        }
        for (int q = j; q < n * 2; q += i) {
          is_max[q] = a[q] == m;
        }
      }
      for (int j = 1; j < n * 2; ++j) {
        if (is_max[j]) {
          is_max[j] += is_max[j - 1];
        }
      }
      cnt[0] = 0;
      for (int j = 1; j < n; ++j) {
        cnt[j] = cnt[j - 1] + (gcd[j] == i);
      }
      for (int j = n; j < n * 2; ++j) {
        ans += cnt[min(is_max[j], n - 1)];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
