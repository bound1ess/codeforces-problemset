#include <iostream>

using namespace std;

void solve(long long l, long long r, long long x, int cnt, int &ans) {
  if (x <= r) {
    if (l <= x && cnt == 1) {
      ++ans;
    }
    if (cnt == 0) {
      solve(l, r, x * 2ll, 1, ans);
    }
    solve(l, r, x * 2ll + 1ll, cnt, ans);
  }
}

int main() {
  int ans = 0;
  long long l, r;
  cin >> l >> r;
  solve(l, r, 1ll, 0, ans);
  cout << ans << endl;
  return 0;
}
