#include <cstdio>

const int N = 30000;
int a[N];

int main() {
  int n, t;
  scanf("%d%d", &n, &t);

  for (int i = 0; i < n - 1; ++i) {
    scanf("%d", a + i);
  }

  int ans = 1;

  while (ans < t) {
    ans += a[ans - 1];
  }

  printf(ans <= t ? "YES\n" : "NO\n");
  return 0;
}
