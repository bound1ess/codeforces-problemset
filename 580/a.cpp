#include <cstdio>

int main() {
  int n, ans = 1;
  scanf("%d", &n);
  int *arr = new int[n], *dp = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
    dp[i] = 1;
  }
  for (int i = 1; i < n; ++i) {
    if (arr[i - 1] <= arr[i]) {
      dp[i] += dp[i - 1];
    }
    if (dp[i] > ans) {
      ans = dp[i];
    }
  }
  printf("%d\n", ans);
  delete[] arr;
  delete[] dp;
  return 0;
}
