#include <cstdio>

const int N = 1234, M = 123456;
char s[N][N];
int x[M], y[M], ans[N][N];
bool stop[N][N];

inline int check_walls(int y, int x, int n, int m) {
  int count = 0;
  if (y > 0 && s[y - 1][x] == '*') {
    ++count;
  }
  if (n > y + 1 && s[y + 1][x] == '*') {
    ++count;
  }
  if (x > 0 && s[y][x - 1] == '*') {
    ++count;
  }
  if (m > x + 1 && s[y][x + 1] == '*') {
    ++count;
  }
  return count;
}

void propagate(int y, int x, int val, int n, int m) {
  if (ans[y][x] == -1) {
    ans[y][x] = val;
    if (y > 0 && s[y - 1][x] == '.') {
      propagate(y - 1, x, val, n, m);
    }
    if (n > y + 1 && s[y + 1][x] == '.') {
      propagate(y + 1, x, val, n, m);
    }
    if (x > 0 && s[y][x - 1] == '.') {
      propagate(y, x - 1, val, n, m);
    }
    if (m > x + 1 && s[y][x + 1] == '.') {
      propagate(y, x + 1, val, n, m);
    }
  }
}

int walk(int y, int x, int n, int m) {
  if ( ! stop[y][x]) {
    stop[y][x] = true;
    int walls = check_walls(y, x, n, m);
    if (y > 0 && s[y - 1][x] == '.') {
      walls += walk(y - 1, x, n, m);
    }
    if (n > y + 1 && s[y + 1][x] == '.') {
      walls += walk(y + 1, x, n, m);
    }
    if (x > 0 && s[y][x - 1] == '.') {
      walls += walk(y, x - 1, n, m);
    }
    if (m > x + 1 && s[y][x + 1] == '.') {
      walls += walk(y, x + 1, n, m);
    }
    return walls;
  } else {
    return 0;
  }
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < k; ++i) {
    scanf("%d%d", y + i, x + i);
    --y[i], --x[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '.') {
        ans[i][j] = -1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '.' && ans[i][j] == -1) {
        propagate(i, j, walk(i, j, n, m), n, m);
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    printf("%d\n", ans[y[i]][x[i]]);
  }
  return 0;
}
