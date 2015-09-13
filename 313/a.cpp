#include <cstdio>

inline int max(int a, int b) {
  return a < b ? b : a;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", max(max(n, n / 10), (n % 10) + (n / 100 * 10)));
  return 0;
}
