#include <iostream>
#include <vector>

using namespace std;

inline int sum(int n) {
  int ans = 0;
  while (n > 0) {
    ans += n % 10, n /= 10;
  }
  return ans;
}

inline long long binpow(int b, int e) {
  long long ans = 1LL, base = (long long) b;
  while (e > 0) {
    if (e % 2 == 1) {
      ans *= base;
    }
    base *= base;
    e /= 2;
  }
  return ans;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<long long> ans;
  for (int i = 1; i <= 81; ++i) {
    long long x = b * binpow(i, a) + c;
    if (sum(x) == i && x < (int) 1e9) {
      ans.push_back(x);
    }
  }
  cout << ans.size() << endl;
  if (ans.size() > 0u) {
    for (int i = 0, m = (int) ans.size(); i < m - 1; ++i) {
      cout << ans[i] << ' ';
    }
    cout << ans[ans.size() - 1u] << endl;
  }
  return 0;
}
