#include <cstdio>

const int M = 13;
int b[M];
bool skip[M][M];

int main() {
  int n, m, x, ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    ++b[x - 1];
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == j || skip[i][j]) {
        continue;
      }
      ans += b[i] * b[j];
      skip[j][i] = true;
    }
  }
  printf("%d\n", ans);
  return 0;
}
