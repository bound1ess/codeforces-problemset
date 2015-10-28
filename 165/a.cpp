#include <cstdio>

const int N = 2002, M = 1001;
bool plane[N][N];
int x[N], y[N];

inline bool check(int x, int y) {
  bool left = false, right = false, lower = false, upper = false;
  for (int i = x - 1; i >= 0; --i) {
    if (plane[y][i]) {
      left = true;
      break;
    }
  }
  for (int i = x + 1; i < N; ++i) {
    if (plane[y][i]) {
      right = true;
      break;
    }
  }
  for (int i = y - 1; i >= 0; --i) {
    if (plane[i][x]) {
      lower = true;
      break;
    }
  }
  for (int i = y + 1; i < N; ++i) {
    if (plane[i][x]) {
      upper = true;
      break;
    }
  }
  return left && right && lower && upper;
}

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", x + i, y + i);
    plane[M + y[i] - 1][M + x[i] - 1] = true;
  }
  for (int i = 0; i < n; ++i) {
    if (check(M + x[i] - 1, M + y[i] - 1)) {
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
