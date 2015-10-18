#include <cstdio>
#include <cassert>

const int N = 100;
int c[N];

int main() {
  int n, k, q, x, ans = 0;
  scanf("%d%d", &n, &k);
  q = n / k;
  assert(q * k == n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    ++c[x - 1];
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      while (c[i] > q && q > c[j]) {
        --c[i], ++c[j];
        ++ans;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
