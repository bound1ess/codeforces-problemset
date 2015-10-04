#include <cstdio>

const int N = 1e3;
int a[N];

int main() {
  int n, go, info = 0, ans = 0, at = 0;
  bool ok, right = true;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  while (info != n) {
    ok = false;
    if (right) {
      for (int i = at; i < n; ++i) {
        if (a[i] <= info && a[i] != -1) {
          go = i;
          ok = true;
          break;
        }
      }
    } else {
      for (int i = at; i >= 0; --i) {
        if (a[i] <= info && a[i] != -1) {
          go = i;
          ok = true;
          break;
        }
      }
    }
    if (ok) {
      at = go;
      a[at] = -1;
      ++info;
    } else {
      right = ! right;
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
