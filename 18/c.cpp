#include <cstdio>

const int N = 100000;
int a[N];

int main() {
  int n, ans = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);

    if (i > 0) {
      a[i] += a[i - 1];
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    if (a[i] == a[n - 1] - a[i]) {
      ++ans;
    }
  }

  printf("%d\n", ans);
  return 0;
}
