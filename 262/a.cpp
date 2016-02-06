#include <cstdio>

inline int count_lucky(int x) {
  int ans = 0;
  while (0 < x) {
    int d = x % 10;
    x /= 10;
    if (4 == d || 7 == d) {
      ++ans;
    }
  }
  return ans;
}

int main() {
  int n, k, x, ans = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    int lucky = count_lucky(x);
    if (lucky <= k) {
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
