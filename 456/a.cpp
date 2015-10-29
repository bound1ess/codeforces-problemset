#include <cstdio>

int main() {
  int n, a, b;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    if (b > a) {
      puts("Happy Alex");
      return 0;
    }
  }
  puts("Poor Alex");
  return 0;
}
