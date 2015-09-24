#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vector< pair<int, int> > v(n);
  long long ans = 0ll, tmp = 0ll;
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  for (int i = 0, j = 0; i < n; ++i) {
    if (v[i].first - d >= v[j].first) {
      ans = max(ans, tmp);
      tmp -= v[j].second;
      ++j, --i;
    } else {
      tmp += v[i].second;
    }
  }
  cout << max(ans, tmp) << endl;
  return 0;
}
