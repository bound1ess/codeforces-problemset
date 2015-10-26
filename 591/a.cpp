#include <cstdio>

int main() {
  int l, p, q;
  scanf("%d%d%d", &l, &p, &q);
  printf("%.17f\n", p * (l / (p + q * 1.)));
  return 0;
}
