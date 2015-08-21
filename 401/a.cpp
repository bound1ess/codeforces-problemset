#include <cstdio>

int main() {
  int n, x, val, sum = 0;
  scanf("%d%d", &n, &x);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &val);
    sum += val;
  }

  if (sum < 0) {
    sum *= -1;
  }

  printf("%d\n", sum / x + (int) (sum % x > 0));
  return 0;
}
