#include <cstdio>

int main() {
  int n, m = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n / 2; ++j, ++m) {
      if (j > 0) {
        putchar(' ');
      }
      printf("%d %d", 1 + m, n * n - m);
    }
    putchar('\n');
  }
  return 0;
}
