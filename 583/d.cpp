#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100;
int a[N];

inline vector<int> build(int n, int t) {
  vector<int> ans(n * t);
  for (int i = 0; i < n * t; ++i) {
    ans[i] = i < n ? a[i] : ans[i - n];
  }
  return ans;
}

inline vector<int> lis(vector<int> a) {
  int n = a.size();
  vector<int> ans(n), dp(n + 1, 500); // magic
  dp[0] = -1;
  for (int i = 0; i < n; ++i) {
    ans[i] = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    dp[ans[i]] = a[i];
  }
  return ans;
}

int main() {
  int n, t, ans = 0;
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  if (t <= n * 2) {
    vector<int> vec = build(n, t);
    vec = lis(vec);
    for (int i = 0; i < n * t; ++i) {
      ans = max(ans, vec[i]);
    }
  } else {
    vector<int> vec = build(n, n);
    vector<int> inc = lis(vec);
    for (int i = 0; i < n * n; ++i) {
      vec[i] = 301 - vec[i]; // magic
    }
    reverse(vec.begin(), vec.end());
    vector<int> dec = lis(vec);
    reverse(dec.begin(), dec.end());
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if (a[i] == a[j]) {
          ++cnt;
        }
      }
      for (int j = 0; j < n; ++j) {
        if (a[j] < a[i]) {
          continue;
        }
        ans = max(ans, inc[(n - 1) * n + i] + cnt * (t - n * 2) + dec[j]);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
