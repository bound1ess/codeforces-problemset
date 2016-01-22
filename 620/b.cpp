#include <cstdio>

const int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
  int l, r, ans = 0;
  scanf("%d%d", &l, &r);
  for (int i = l; i <= r; ++i) {
    int x = i;
    while (x > 0) {
      ans += a[x % 10];
      x /= 10;
    }
  }
  printf("%d\n", ans);
  return 0;
}
