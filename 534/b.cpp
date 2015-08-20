#include <cstdio>

const int N = 100;
int l[N], r[N];

inline int min(int x, int y) {
  return x < y ? x : y;
}

int main() {
  int t, d, ans = 0;
  scanf("%d%d%d%d", l, r, &t, &d);

  for (int i = 1; i < t; ++i) {
    l[i] = d + l[i - 1];
    r[i] = d + r[i - 1];
  }

  for (int i = 0; i < t; ++i) {
    ans += min(l[i], r[t - i - 1]);
  }

  printf("%d\n", ans);
  return 0;
}
