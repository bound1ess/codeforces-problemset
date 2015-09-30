#include <cstdio>

int main() {
  int n, x, ans = 0;
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; ++i) {
    if (x % i == 0 && x / i <= n) {
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
