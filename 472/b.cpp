#include <cstdio>
#include <algorithm>

const int N = 12345;
int a[N];

int main() {
  int n, k, ans = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::sort(a, a + n);
  for (int i = n - 1; i >= 0; i -= k) {
    ans += (a[i] - 1) * 2;
  }
  printf("%d\n", ans);
  return 0;
}
