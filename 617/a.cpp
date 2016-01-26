#include <cstdio>

int main() {
  int x, ans = 0, k = 5;
  scanf("%d", &x);
  while (x > 0) {
    ans += x / k;
    x %= k;
    --k;
  }
  printf("%d\n", ans);
  return 0;
}
