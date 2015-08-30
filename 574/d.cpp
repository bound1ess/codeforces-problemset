#include <cstdio>

const int N = 1e5;
int dp[N], a[N];

inline int min(int x, int y) {
  return x < y ? x : y;
}

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  dp[0] = 1;

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }

  for (int i = 0; i < n; ++i) {
    dp[i] = min(a[i], i + 1);
    dp[i] = min(dp[i], dp[i - 1] + 1);
  }

  dp[n - 1] = 1;

  for (int i = n - 2; i >= 0; --i) {
    dp[i] = min(dp[i], n - i);
    dp[i] = min(dp[i], dp[i + 1] + 1);
  }

  for (int i = 0; i < n; ++i) {
    if (dp[i] > ans) {
      ans = dp[i];
    }
  }

  printf("%d\n", ans);
  return 0;
}
