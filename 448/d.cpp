#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long l = 1LL, r = (n * m) + 1LL;

  while (l < r) {
    long long mid = (l + r) / 2LL, sum = 0LL;

    for (long long i = 1LL; i <= n; ++i) {
      sum += min(m, (mid - 1LL) / i);
    }

    if (sum < k) {
      l = mid + 1LL;
    } else {
      r = mid;
    }
  }

  cout << (l - 1LL) << endl;
  return 0;
}
