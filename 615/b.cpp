#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, u, v;
  long long ans = 0ll;
  scanf("%d%d", &n, &m);
  vector<int> dp(n, 1);
  vector< vector<int> > g(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0, k = int(g[i].size()); j < k; ++j) {
      if (i > g[i][j]) {
        dp[i] = max(dp[i], dp[g[i][j]] + 1);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    ans = max(ans, (long long) g[i].size() * dp[i]);
  }
  cout << ans << endl;
  return 0;
}
