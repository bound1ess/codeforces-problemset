#include <iostream>

using namespace std;

const int N = 200100, MOD = (int) 1e9 + 7;
int p[N];

inline long long power(long long b, long long exp) {
  long long ans = 1ll;
  while (exp > 0ll) {
    if (exp % 2ll == 1ll) {
      ans = (ans * b) % MOD;
    }
    exp /= 2ll;
    b = (b * b) % MOD;
  }
  return ans;
}

int main() {
  int n, x;
  long long ans = 1ll, res = 1ll;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    ++p[x];
  }
  for (int i = 0; i < N; ++i) {
    if (p[i] == 0) {
      continue;
    }
    long long val = (((p[i] + 1ll) * p[i] / 2ll) % (MOD - 1)) * (res % (MOD - 1));
    ans = (power((long long) i, val) * power(ans, p[i] + 1ll)) % MOD;
    res = (res * (p[i] + 1ll)) % (MOD - 1);
  }
  cout << ans << endl;
  return 0;
}
