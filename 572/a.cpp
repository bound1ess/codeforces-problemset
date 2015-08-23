#include <cstdio>

const int N = 100000;
int a[N], b[N];

int main() {
  int n1, n2, k, m;
  scanf("%d%d%d%d", &n1, &n2, &k, &m);

  for (int i = 0; i < n1; ++i) {
    scanf("%d", a + i);
  }

  for (int i = 0; i < n2; ++i) {
    scanf("%d", b + i);
  }

  printf(a[k - 1] < b[n2 - m] ? "YES\n" : "NO\n");
  return 0;
}
