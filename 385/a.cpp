#include <cstdio>

const int N = 123;
int a[N];

int main() {
  int n, c, ans = 0;
  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n - 1; ++i) {
    int res = a[i] - a[i + 1] - c;
    if (res > ans) {
      ans = res;
    }
  }
  printf("%d\n", ans);
  return 0;
}
