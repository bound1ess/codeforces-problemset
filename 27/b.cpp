#include <cstdio>
#include <vector>

using namespace std;

const int N = 123;
int won[N], lost[N];

int main() {
  int n, m, x, y;
  scanf("%d", &n);
  m = n * (n - 1) / 2 - 1;
  vector< pair<int, int> > a, b;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    --x, --y;
    a.push_back(make_pair(x, y));
    ++won[x], ++lost[y];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      b.push_back(make_pair(i, j));
    }
  }
  for (int i = 0; i < m + 1; ++i) {
    bool found = false;
    for (int j = 0; j < m; ++j) {
      bool check = (min(a[j].first, a[j].second) == min(b[i].first, b[i].second))
        && (max(a[j].first, a[j].second) == max(b[i].first, b[i].second));
      if (check) {
        found = true;
        break;
      }
    }
    if ( ! found) {
      x = b[i].first, y = b[i].second;
      if (won[x] > won[y] || lost[x] < lost[y]) {
        printf("%d %d\n", x + 1, y + 1);
      } else {
        printf("%d %d\n", y + 1, x + 1);
      }
      return 0;
    }
  }
  return 0;
}
