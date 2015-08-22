#include <cstdio>

const int N = 1000;

inline int squared(int x) {
  return x * x;
}

int main() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);

  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      if (squared(i) + j == n && i + squared(j) == m) {
        ++ans;
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
