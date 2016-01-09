#include <cstdio>

const int N = 123;
char s[N];
int g[N][N];

int main() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int j = 0; j < m; ++j) {
      g[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      bool best = true;
      for (int k = 0; k < n; ++k) {
        if (i != k && g[k][j] > g[i][j]) {
          best = false;
          break;
        }
      }
      if (best) {
        ++ans;
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
