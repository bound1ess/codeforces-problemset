#include <cstdio>
#include <cmath>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%d\n", 4 * int(sqrt(a * b / c + b * c / a + c * a / b + 2 * (a + b + c))));
  return 0;
}
