#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n % 2 == 1 ? 0 : (n % 4 == 0 ? n / 4 - 1 : n / 4));
  return 0;
}
