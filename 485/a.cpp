#include <cstdio>

int main() {
  int a, m;
  scanf("%d%d", &a, &m);

  for (int i = 0; i <= m; ++i) {
    a *= 2, a %= m;
  }

  printf(a == 0 ? "Yes\n" : "No\n");
  return 0;
}
