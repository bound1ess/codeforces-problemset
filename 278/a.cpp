#include <cstdio>

const int N = 123;
int d[N];

int main() {
  int n, s, t, sc, tc, ans1 = 0, ans2 = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", d + i);
  }
  scanf("%d%d", &s, &t);
  --s, --t;
  if (s > t) {
    int z = s;
    s = t, t = z;
  }
  sc = s, tc = t;
  while (s != t) {
    ans1 += d[s], ++s;
  }
  while (sc != tc) {
    ans2 += d[tc], ++tc;
    if (tc == n) {
      tc = 0;
    }
  }
  printf("%d\n", ans1 < ans2 ? ans1 : ans2);
  return 0;
}
