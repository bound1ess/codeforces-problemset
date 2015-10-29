#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  if (n % 2 == 1) {
    puts("-1");
    return 0;
  }
  for (int i = 2; i <= n; i += 2) {
    if (i > 2) {
      putchar(' ');
    }
    printf("%d %d", i, i - 1);
  }
  putchar('\n');
  return 0;
}
