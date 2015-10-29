#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n, a, b, ans = -1;
  scanf("%d", &n);
  vector< pair<int, int> > v;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    if (ans <= v[i].second) {
      ans = v[i].second;
    } else {
      ans = v[i].first;
    }
  }
  printf("%d\n", ans);
  return 0;
}
