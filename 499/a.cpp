#include <cstdio>

const int N = 50;
int l[N], r[N];

int main() {
  int n, x;
  scanf("%d%d", &n, &x);

  for (int i = 0; i < n; ++i) {
    scanf("%d%d", l + i, r + i);
  }

  int ans = (l[0] - 1) % x;

  for (int i = 0; i < n; ++i) {
    ans += (r[i] - l[i]) + 1;
  }

  for (int i = 1; i < n; ++i) {
    ans += (l[i] - (1 + r[i - 1])) % x;
  }

  printf("%d\n", ans);
  return 0;
}
