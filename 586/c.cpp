#include <cstdio>

const int N = 4000;
int v[N], d[N], out[N];
bool ready[N];
long long p[N];

int main() {
  int n, x, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", v + i, d + i, &x);
    p[i] = (long long) x;
    ready[i] = true;
  }
  for (int i = 0; i < n; ++i) {
    if (ready[i]) {
      out[ans] = i + 1;
      ++ans;
      int dec = v[i];
      for (int j = i + 1; j < n && dec > 0; ++j) {
        if (ready[j]) {
          p[j] -= (long long) dec;
          --dec;
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      if (p[j] < 0ll && ready[j]) {
        ready[j] = false;
        for (int k = j + 1; k < n; ++k) {
          p[k] -= (long long) d[j];
        }
      }
    }
  }
  printf("%d\n", ans);
  if (ans > 0) {
    for (int i = 0; i < ans - 1; ++i) {
      printf("%d ", out[i]);
    }
    printf("%d\n", out[ans - 1]);
  }
  return 0;
}
