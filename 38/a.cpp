#include <cstdio>

const int N = 100;
int d[N];

int main() {
  int n, a, b;
  scanf("%d", &n);

  for (int i = 0; i < n - 1; ++i) {
    scanf("%d", d + i);

    if (i > 0) {
      d[i] += d[i - 1];
    }
  }

  scanf("%d%d", &a, &b);

  printf("%d\n", d[b - 2] - d[a - 2]);
  return 0;
}
