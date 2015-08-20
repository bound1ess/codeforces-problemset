#include <cstdio>

const int N = 100000;
int a[N], b[N];
bool c[N];

int main() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d", b + i);
  }

  for (int i = 0; i < n; ++i) {
    bool make = true;

    for (int j = 0; j < m; ++j) {
      if (c[j]) {
        continue;
      }

      if (b[j] >= a[i]) {
        c[j] = true;
        make = false;
        break;
      }
    }

    if (make) {
      ++ans;
    }
  }

  printf("%d\n", ans);
  return 0;
}
