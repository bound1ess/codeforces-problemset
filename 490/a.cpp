#include <cstdio>

const int N = 5000, M = 3;
int a[M], t[M][N];

inline int min(int x, int y) {
  return x < y ? x : y;
}

int main() {
  int n, x;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    --x;

    t[x][a[x]] = i + 1;
    ++a[x];
  }

  int ans = min(a[0], min(a[1], a[2]));
  printf("%d\n", ans);

  for (int i = 0; i < ans; ++i) {
    printf("%d %d %d\n", t[0][i], t[1][i], t[2][i]);
  }

  return 0;
}
