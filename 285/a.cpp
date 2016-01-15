#include <cstdio>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k == 0) {
    for (int i = 0; i < n; ++i) {
      if (i > 0) {
        putchar(' ');
      }
      printf("%d", i + 1);
    }
    putchar('\n');
  } else {
    for (int i = n - 1; n - k - 1 < i; --i) {
      if (n - 1 != i) {
        putchar(' ');
      }
      printf("%d", i + 1);
    }
    for (int i = 0; i < n - k; ++i) {
      printf(" %d", i + 1);
    }
    putchar('\n');
  }
  return 0;
}
