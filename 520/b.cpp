#include <cstdio>

int main() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);
  while (n != m) {
    if (n > m) {
      ++m, ++ans;
    } else {
      if (m % 2 == 0) {
        m /= 2, ++ans;
      } else {
        ++m, ++ans;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
