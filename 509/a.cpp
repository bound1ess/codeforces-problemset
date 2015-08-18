#include <cstdio>

const int N = 10;
int a[N][N];

int main() {
  int n, ans = 1;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    a[i][0] = 1;

    if (i < 1) {
      for (int j = 1; j < n; ++j) {
        a[i][j] = 1;
      }
    }
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      a[i][j] = a[i - 1][j] + a[i][j - 1];

      if (ans < a[i][j]) {
        ans = a[i][j];
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
