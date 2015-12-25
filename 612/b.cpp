#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n, x;
  long long ans = 0ll;
  vector< pair<int, int> > v;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    v.push_back(make_pair(x, i));
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < n; ++i) {
    ans += abs(v[i].second - v[i - 1].second);
  }
  cout << ans << endl;
  return 0;
}
