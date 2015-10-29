#include <cstdio>

const int N = 4001;

int main() {
  int n, a, b, c, ans = 0;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int tmp = a * i + b * j;
      int z = (n - tmp) / c;
      if (z >= 0 && z * c == n - tmp && i + j + z > ans) {
        ans = i + j + z;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
