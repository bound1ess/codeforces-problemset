#include <cstdio>

const int N = 1234;
int a[N];

int main() {
  int n, m, k, ans = 0;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    if (a[i] == 1) {
      if (m > 0) {
        --m;
      } else {
        ++ans;
      }
    } else {
      if (k > 0) {
        --k;
      } else if (m > 0) {
        --m;
      } else {
        ++ans;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
