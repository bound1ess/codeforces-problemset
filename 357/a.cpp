#include <cstdio>

const int N = 100;
int c[N];

int main() {
  int m, x, y;
  scanf("%d", &m);

  for (int i = 0; i < m; ++i) {
    scanf("%d", c + i);

    if (i > 0) {
      c[i] += c[i - 1];
    }
  }

  scanf("%d%d", &x, &y);

  for (int i = 0; i < m; ++i) {
    if (c[i] >= x && y >= c[i] && c[m - 1] - c[i] >= x && y >= c[m - 1] - c[i]) {
      printf("%d\n", i + 2);
      return 0;
    }
  }

  printf("0\n");
  return 0;
}
