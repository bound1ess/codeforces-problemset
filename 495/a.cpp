#include <cstdio>

int a[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", a[n / 10] * a[n % 10]);
  return 0;
}
