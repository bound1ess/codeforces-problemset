#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  switch (n) {
    case 1:
    case 2:
      puts("1");
      puts("1");
      break;
    case 3:
      puts("2");
      puts("1 3");
      break;
    default:
      printf("%d\n", n);
      for (int i = n; i >= 1; --i) {
        if (i % 2 == 1) {
          printf("%d ", i);
        }
      }
      for (int i = n; i >= 2; --i) {
        if (i % 2 == 0) {
          printf("%d", i);
          putchar(i == 2 ? '\n' : ' ');
        }
      }
  }
  return 0;
}
