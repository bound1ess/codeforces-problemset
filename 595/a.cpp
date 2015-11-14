#include <cstdio>

const int N = 1234;
int a[N][N];

int main() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m * 2; ++j) {
      scanf("%d", a[i] + j);
    }
    for (int j = 0; j < m * 2 - 1; j += 2) {
      if (a[i][j] == 1 || a[i][j + 1] == 1) {
        ++ans;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
