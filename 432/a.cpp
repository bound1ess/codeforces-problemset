#include <cstdio>

int main() {
  int n, k, x, ans = 0;
  scanf("%d%d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);

    if (x <= 5 - k) {
      ++ans;
    }
  }

  printf("%d\n", ans / 3);
  return 0;
}
