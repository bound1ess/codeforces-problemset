#include <iostream>
#include <algorithm>

using namespace std;

const int N = 123456;
int cnt[N];
long long dp[N];

int main() {
  ios_base::sync_with_stdio(false);
  int n, x;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    ++cnt[x];
  }
  dp[0] = 0LL;
  dp[1] = (long long) cnt[1];
  for (int i = 2; i < N; ++i) {
    dp[i] = max(dp[i - 1], dp[i - 2] + (long long) cnt[i] * i);
  }
  cout << dp[N - 1] << endl;
  return 0;
}
