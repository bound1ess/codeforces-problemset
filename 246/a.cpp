#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  if (n <= 2) {
    puts("-1");
    return 0;
  }
  for (int i = n - 1; 0 <= i; --i) {
    if (i < n - 1) {
      putchar(' ');
    }
    printf("%d", i + 1);
  }
  putchar('\n');
  return 0;
}
