#include <cstdio>

int main() {
  int d, l, v1, v2;
  scanf("%d%d%d%d", &d, &l, &v1, &v2);
  printf("%.17f\n", double(l - d) / (v1 + v2));
  return 0;
}
