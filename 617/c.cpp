#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
typedef pair <long long, long long> llp;

inline llp read_pair() {
  llp x;
  cin >> x.first >> x.second;
  return x;
}

inline long long square(long long x) {
  return x * x;
}

inline long long dist(const llp &a, const llp &b) {
  return square(a.first - b.first) + square(a.second - b.second);
}

int main() {
  int n;
  cin >> n;
  llp a = read_pair(), b = read_pair();
  vector <llp> v;
  for (int i = 0; i < n; ++i) {
    llp c = read_pair();
    v.push_back(make_pair(dist(a, c), dist(b, c)));
  }
  sort(v.begin(), v.end());
  long long ans = (long long) 1e18, res;
  for (int i = 0; i <= n; ++i) {
    res = 0LL;
    for (int j = i; j < n; ++j) {
      res = max(res, v[j].second);
    }
    ans = min(ans, res + (i > 0 ? v[i - 1].first : 0LL));
  }
  cout << ans << endl;
  return 0;
}
