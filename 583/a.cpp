#include <cstdio>

const int N = 50;
int hr[N], vr[N], ans[N * N];

int main() {
  int n, h, v, cnt = 0;
  scanf("%d", &n);
  for (int i = 0; i < n * n; ++i) {
    scanf("%d%d", &h, &v);
    --h, --v;
    if ( ! hr[h] && ! vr[v]) {
      ans[cnt] = i + 1;
      ++cnt;
      hr[h] = vr[v] = true;
    }
  }
  for (int i = 0; i < cnt - 1; ++i) {
    printf("%d ", ans[i]);
  }
  printf("%d\n", ans[cnt - 1]);
  return 0;
}
