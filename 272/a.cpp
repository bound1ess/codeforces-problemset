#include <cstdio>

int main() {
  int n, m, f = 0, ans = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &m);
    f += m;
  }

  for (int i = 1; i <= 5; ++i) {
    if ((f + i) % (n + 1) != 1) {
      ++ans;
    }
  }

  printf("%d\n", ans);
  return 0;
}
