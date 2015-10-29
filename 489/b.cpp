#include <cstdio>
#include <algorithm>

const int N = 123;
int a[N], b[N];

inline int custom_abs(int n) {
  return n < 0 ? -n : n;
}

int main() {
  int n, m, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", b + i);
  }
  std::sort(a, a + n), std::sort(b, b + m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (custom_abs(a[i] - b[j]) <= 1) {
        b[j] = 1e9, ++ans;
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
