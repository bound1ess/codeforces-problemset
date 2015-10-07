#include <cstdio>

inline bool check(int n) {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  if (check(n)) {
    printf("1\n%d\n", n);
    return 0;
  }
  int p = n - 2;
  while ( ! check(p)) {
    --p;
  }
  for (int i = 2; n - p >= i; ++i) {
    if (check(i) && p + i == n) {
      printf("2\n%d %d\n", p, i);
      break;
    }
    if (check(i) && check(n - p - i)) {
      printf("3\n%d %d %d\n", p, i, n - p - i);
      break;
    }
  }
  return 0;
}
