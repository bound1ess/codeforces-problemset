#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  printf("%d", n);
  for (int i = 0; i < n - 1; ++i) {
    printf(" %d", i + 1);
  }
  putchar('\n');
  return 0;
}
