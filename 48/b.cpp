#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 123;
bool g[N][N];

inline int solve(int n, int m, int h, int w) {
  int ans = 123456789;
  for (int i = 0; i < n - h + 1; ++i) {
    for (int j = 0; j < m - w + 1; ++j) {
      int res = 0;
      for (int k = 0; k < h; ++k) {
        for (int q = 0; q < w; ++q) {
          res += (g[i + k][j + q] == 1);
        }
      }
      ans = min(ans, res);
    }
  }
  return ans;
}

int main() {
  int n, m, x, a, b;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &x);
      g[i][j] = (x == 1);
    }
  }
  scanf("%d%d", &a, &b);
  printf("%d\n", min(solve(n, m, a, b), solve(n, m, b, a)));
  return 0;
}
