#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3;
vector < pair <int, int> > v(N);

inline int solve() {
  sort(v.begin(), v.end());
  if (v[0].first == v[1].first && v[1].first == v[2].first) {
    return 1;
  }
  if (v[0].first == v[1].first) {
    return v[0].second < v[2].second && v[2].second < v[1].second ? 3 : 2;
  }
  if (v[1].first == v[2].first) {
    return v[1].second < v[0].second && v[0].second < v[2].second ? 3 : 2;
  }
  return 3;
}

int main() {
  for (int i = 0; i < N; ++i) {
    scanf("%d%d", &v[i].first, &v[i].second);
  }
  int ans = solve();
  for (int i = 0; i < N; ++i) {
    swap(v[i].first, v[i].second);
  }
  printf("%d\n", min(ans, solve()));
  return 0;
}
