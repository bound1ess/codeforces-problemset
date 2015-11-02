#include <iostream>

using namespace std;

long long gcd(long long x, long long y) {
  if (y > x) {
    return gcd(y, x);
  }
  long long z;
  while (y > 0LL) {
    z = x % y;
    x = y, y = z;
  }
  return x;
}

long long min(long long x, long long y) {
  return x < y ? x : y;
}

int main() {
  long long t, w, b, k, ans, cd, l;
  cin >> t >> w >> b;
  cd = gcd(w, b), k = w / cd;
  l = min(w, b) - 1LL;
  ans = t / k / b;
  ans *= 1LL + l;
  ans += min(t - (t / k / b) * k * b, l);
  cd = gcd(ans, t);
  ans /= cd, t /= cd;
  cout << ans << '/' << t << endl;
  return 0;
}
