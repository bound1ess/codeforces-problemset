#include <cstdio>

int main() {
  int n, m, x, ans = 0, tmp = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (tmp + x <= m) {
      tmp += x;
    } else {
      ++ans;
      tmp = x;
    }
  }
  printf("%d\n", ans + 1);
  return 0;
}
