#include <cstdio>

int main() {
  int n, m, curr = 1;
  scanf("%d%d", &n, &m);
  while (curr <= m) {
    m -= curr, ++curr;
    if (curr == n + 1) {
      curr = 1;
    }
  }
  printf("%d\n", m);
  return 0;
}
