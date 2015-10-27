#include <cstdio>

const int N = 1234;
int a[N];

inline int count(int x) {
  int ans = 0;
  for (int i = 1; i <= x; i <<= 1) {
    if ((x & i) > 0) {
      ++ans;
    }
  }
  return ans;
}

int main() {
  int n, m, k, ans = 0;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i <= m; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < m; ++i) {
    if (count(a[i] ^ a[m]) <= k) {
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
