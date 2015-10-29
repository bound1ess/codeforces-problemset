#include <cstdio>

const int N = 1234;
bool grid[N][N];
int ans = 0;

inline void stop(int move) {
  if (ans == 0) {
    ans = move + 1;
  }
}

int main() {
  int n, m, k, x, y;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d%d", &y, &x);
    --x, --y;
    grid[y][x] = true;
    if (y + 1 < n && x + 1 < m) {
      if (grid[y][x] && grid[y + 1][x] && grid[y][x + 1] && grid[y + 1][x + 1]) {
        stop(i);
      }
    }
    if (y + 1 < n && x - 1 >= 0) {
      if (grid[y][x] && grid[y + 1][x] && grid[y][x - 1] && grid[y + 1][x - 1]) {
        stop(i);
      }
    }
    if (y - 1 >= 0 && x + 1 < m) {
      if (grid[y][x] && grid[y - 1][x] && grid[y][x + 1] && grid[y - 1][x + 1]) {
        stop(i);
      }
    }
    if (y - 1 >= 0 && x - 1 >= 0) {
      if (grid[y][x] && grid[y - 1][x] && grid[y][x - 1] && grid[y - 1][x - 1]) {
        stop(i);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
