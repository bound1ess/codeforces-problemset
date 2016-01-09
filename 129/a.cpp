#include <cstdio>

const int N = 123;
int a[N];

int main() {
  int n, ans = 0, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    sum += a[i];
  }
  for (int i = 0; i < n; ++i) {
    if ((sum - a[i]) % 2 == 0) {
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
