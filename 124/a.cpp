#include <cstdio>

inline int max(int a, int b) {
  return a < b ? b : a;
}

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  printf("%d\n", n + 1 - max(n - b, a + 1));
  return 0;
}
