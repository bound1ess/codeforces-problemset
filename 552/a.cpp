#include <cstdio>

const int N = 100;
int grid[N][N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    for (int j = x1 - 1; j < x2; ++j) {
      for (int k = y1 - 1; k < y2; ++k) {
        ++grid[j][k];
      }
    }
  }

  int sum = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      sum += grid[i][j];
    }
  }

  printf("%d\n", sum);
  return 0;
}
