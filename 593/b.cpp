#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
  int n, k, b, x1, x2;
  scanf("%d%d%d", &n, &x1, &x2);
  vector< pair<long long, long long> > v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &k, &b);
    v[i].first = (long long) k * x1 + b;
    v[i].second = (long long) k * x2 + b;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n - 1; ++i) {
    if (v[i].second > v[i + 1].second) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
