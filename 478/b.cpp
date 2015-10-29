#include <iostream>

using namespace std;

inline long long pairs(long long n) {
  return (n * (n - 1LL)) >> 1;
}

inline long long solve(long long a, long long b, long long c, long long d) {
  return a * pairs(b) + c * pairs(d);
}

int main() {
  long long n, m;
  cin >> n >> m;
  cout << solve(n % m, n / m + 1LL, m - (n % m), n / m);
  cout << ' ';
  cout << solve(m - 1LL, 1LL, 1LL, n - m + 1LL);
  cout << endl;
  return 0;
}
