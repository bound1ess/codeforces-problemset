#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

const int N = 123, MIN_WALK_LEN = 4;
char s[N][N];
vector < pair <int, int> > g[N][N];
bool vis[N][N];

bool cycle(int x, int y, int orig_x, int orig_y, int walk_len) {
  if (vis[y][x]) {
    return orig_x == x && orig_y == y && MIN_WALK_LEN <= walk_len;
  }
  vis[y][x] = true;
  for (int i = 0, n = int(g[y][x].size()); i < n; ++i) {
    if (cycle(g[y][x][i].first, g[y][x][i].second, orig_x, orig_y, walk_len + 1)) {
      return true;
    }
  }
  vis[y][x] = false;
  return false;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (0 < i && s[i - 1][j] == s[i][j]) {
        g[i][j].push_back(make_pair(j, i - 1));
      }
      if (i + 1 < n && s[i + 1][j] == s[i][j]) {
        g[i][j].push_back(make_pair(j, i + 1));
      }
      if (0 < j && s[i][j - 1] == s[i][j]) {
        g[i][j].push_back(make_pair(j - 1, i));
      }
      if (j + 1 < m && s[i][j + 1] == s[i][j]) {
        g[i][j].push_back(make_pair(j + 1, i));
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (cycle(j, i, j, i, 1)) {
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}
