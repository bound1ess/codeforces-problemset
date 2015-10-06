#include <iostream>

using namespace std;

const long long MOD = (long long) 1e9 + 7LL;

int main() {
  long long a, b, c, d, e;
  cin >> a >> b;
  c = (b * (b - 1LL) / 2LL) % MOD;
  d = (a * (a + 1LL) / 2LL) % MOD;
  e = (d * b + a) % MOD;
  cout << ((c * e) % MOD) << endl;
  return 0;
}
