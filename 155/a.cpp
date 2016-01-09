#include <cstdio>

int main() {
  int n, x, best = 0, worst = 0, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (i > 0) {
      if (worst > x) {
        ++ans;
        worst = x;
      }
      if (x > best) {
        ++ans;
        best = x;
      }
    } else {
      worst = best = x;
    }
  }
  printf("%d\n", ans);
  return 0;
}
