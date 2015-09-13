#include <cstdio>

int main() {
  int n, sum = 0, h = 0;
  scanf("%d", &n);

  while (sum <= n) {
    ++h, sum += h * (h + 1) / 2;
  }

  printf("%d\n", h - 1);
  return 0;
}
