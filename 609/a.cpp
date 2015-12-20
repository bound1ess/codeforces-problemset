#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int N = 123;
int a[N];

int main() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  sort(a, a + n, greater<int>());
  for (int i = 0; i < n && m > 0; ++i) {
    ++ans, m -= a[i];
  }
  printf("%d\n", ans);
  return 0;
}
