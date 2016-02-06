#include <cstdio>

const int N = 1234;
char s[N][N];
bool vis[N][N];

void modify(int x, int y, int total, int n, int m, int &completed) {
  if (vis[y][x]) {
    return;
  }
  ++completed, vis[y][x] = true;
  if (completed > total) {
    s[y][x] = 'X';
  }
  if (0 < y && s[y - 1][x] == '.') {
    modify(x, y - 1, total, n, m, completed);
  }
  if (y + 1 < n && s[y + 1][x] == '.') {
    modify(x, y + 1, total, n, m, completed);
  }
  if (0 < x && s[y][x - 1] == '.') {
    modify(x - 1, y, total, n, m, completed);
  }
  if (x + 1 < m && s[y][x + 1] == '.') {
    modify(x + 1, y, total, n, m, completed);
  }
}

int main() {
  int n, m, k, x, y, free = 0;
  bool found = false;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '.') {
        x = j, y = i;
        ++free;
        found = true;
      }
    }
  }
  if (found) {
    int completed = 0;
    modify(x, y, free - k, n, m, completed);
  }
  for (int i = 0; i < n; ++i) {
    printf("%s\n", s[i]);
  }
  return 0;
}
