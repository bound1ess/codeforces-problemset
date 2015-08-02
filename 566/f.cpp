#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1234567;
int dp[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    dp[x] = 1;
  }

  for (int i = 0; i < N; ++i) {
    if (dp[i] > 0) {
      for (int j = i * 2; j < N; j += i) {
        if (dp[j] > 0) {
          dp[j] = max(dp[j], dp[i] + 1);
        }
      }
    }
  }

  int ans = 1;

  for (int i = 0; i < N; ++i) {
    ans = max(ans, dp[i]);
  }

  printf("%d\n", ans);
  return 0;
}
