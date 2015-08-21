#include <cstdio>

const int N = 7;
int a[N];

int main() {
  int n, ans = 0;
  scanf("%d", &n);

  for (int i = 0; i < N; ++i) {
    scanf("%d", a + i);
  }

  while (n > 0) {
    n -= a[ans % N];
    ++ans;
  }

  printf("%d\n", ans % N == 0 ? N : (ans % N));
  return 0;
}
