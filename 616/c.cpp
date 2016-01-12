#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int N = 1234;
int ans[N][N], id[N][N], curr_id = 1;
char g[N][N];
bool vis[N][N];

inline int merge(int y, int x, int n, int m) {
  int result = 1;
  set<int> ids;
  if (y > 0 && ans[y - 1][x] != -1) {
    result += ans[y - 1][x];
    ids.insert(id[y - 1][x]);
  }
  if (n > y + 1 && ans[y + 1][x] != -1 && ids.count(id[y + 1][x]) == 0) {
    result += ans[y + 1][x];
    ids.insert(id[y + 1][x]);
  }
  if (x > 0 && ans[y][x - 1] != -1 && ids.count(id[y][x - 1]) == 0) {
    result += ans[y][x - 1];
    ids.insert(id[y][x - 1]);
  }
  if (m > x + 1 && ans[y][x + 1] != -1 && ids.count(id[y][x + 1]) == 0) {
    result += ans[y][x + 1];
  }
  return result;
}

int solve(int y, int x, int n, int m) {
  if (vis[y][x] || g[y][x] == '*') {
    return 0;
  }
  vis[y][x] = true;
  int result = 1;
  if (y > 0) {
    result += solve(y - 1, x, n, m);
  }
  if (n > y + 1) {
    result += solve(y + 1, x, n, m);
  }
  if (x > 0) {
    result += solve(y, x - 1, n, m);
  }
  if (m > x + 1) {
    result += solve(y, x + 1, n, m);
  }
  return result;
}

void push(int y, int x, int n, int m, int val) {
  if (ans[y][x] == -1 && g[y][x] == '.') {
    ans[y][x] = val;
    id[y][x] = curr_id;
    if (y > 0) {
      push(y - 1, x, n, m, val);
    }
    if (n > y + 1) {
      push(y + 1, x, n, m, val);
    }
    if (x > 0) {
      push(y, x - 1, n, m, val);
    }
    if (m > x + 1) {
      push(y, x + 1, n, m, val);
    }
  }
}

int main() {
  int n, m;
  string tmp;
  vector<string> v;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", g[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans[i][j] = -1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (ans[i][j] == -1 && g[i][j] == '.') {
        push(i, j, n, m, solve(i, j, n, m));
        ++curr_id;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    tmp.clear();
    for (int j = 0; j < m; ++j) {
      if (g[i][j] == '*') {
        tmp += '0' + (merge(i, j, n, m) % 10);
      } else {
        tmp += '.';
      }
    }
    v.push_back(tmp);
  }
  for (int i = 0; i < n; ++i) {
    cout << v[i] << '\n';
  }
  return 0;
}
