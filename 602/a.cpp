#include <cstdio>

inline long long binpow(int real_base, int exp) {
  long long ans = 1ll, base = (long long) real_base;
  while (exp > 0) {
    if (exp % 2 == 1) {
      ans *= base;
    }
    exp /= 2;
    base *= base;
  }
  return ans;
}

int main() {
  int n, m, a, b, d;
  long long x = 0ll, y = 0ll;
  scanf("%d%d", &n, &a);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d);
    x += (long long) d * binpow(a, n - i - 1);
  }
  scanf("%d%d", &m, &b);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &d);
    y += (long long) d * binpow(b, m - i - 1);
  }
  puts(x == y ? "=" : (x > y ? ">" : "<"));
  return 0;
}
