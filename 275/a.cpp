#include <cstdio>

const int N = 3;
bool g[N][N];
int c[N][N];

inline void toggle(int x, int y) {
  g[y][x] = ! g[y][x];
}

inline void go(int x, int y) {
  toggle(x, y);
  if (0 < x) {
    toggle(x - 1, y);
  }
  if (x + 1 < N) {
    toggle(x + 1, y);
  }
  if (0 < y) {
    toggle(x, y - 1);
  }
  if (y + 1 < N) {
    toggle(x, y + 1);
  }
}

int main() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%d", c[i] + j);
      g[i][j] = true;
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (c[i][j] % 2 == 1) {
        go(j, i);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      putchar(g[i][j] ? '1' : '0');
    }
    putchar('\n');
  }
  return 0;
}
