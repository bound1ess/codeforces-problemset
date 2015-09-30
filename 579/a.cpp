#include <cstdio>

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i <<= 1) {
    if (i & n) {
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
