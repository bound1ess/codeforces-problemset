#include <cstdio>

const int N = 100, PAUSE = 10, JOKE = 5;
int a[N];

int main() {
  int n, d, sum = 0;
  scanf("%d%d", &n, &d);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    sum += a[i];
  }

  if (sum + (n - 1) * PAUSE > d) {
    printf("-1\n");
  } else {
    printf("%d\n", (d - sum) / JOKE);
  }

  return 0;
}
