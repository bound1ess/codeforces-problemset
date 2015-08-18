#include <cstdio>

const int N = 30;
int a[N][N], row[N], col[N];

int main() {
  int n; scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", a[i] + j);
      col[j] += a[i][j];
      row[i] += a[i][j];
    }
  }

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (col[j] > row[i]) {
        ++ans;
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
