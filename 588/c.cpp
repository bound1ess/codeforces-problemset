#include <cstdio>

const int N = 1234567;
int b[N];

int main() {
  int n, x, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    ++b[x];
  }
  x = 0;
  for (int i = 0; i < N; ++i) {
    x += b[i];
    if (x % 2 != 0) {
      ++ans;
    }
    x >>= 1;
  }
  printf("%d\n", ans);
  return 0;
}
