#include <cstdio>

int main() {
  int n, s, x, max = 0, sum = 0;
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    sum += x;
    if (x > max) {
      max = x;
    }
  }
  puts(sum - max <= s ? "YES" : "NO");
  return 0;
}
