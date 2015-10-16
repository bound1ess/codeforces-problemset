#include <cstdio>

int main() {
  int n, total = 0, lowest = 1e9, price, meat;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &meat, &price);
    if (lowest > price) {
      lowest = price;
    }
    total += lowest * meat;
  }
  printf("%d\n", total);
  return 0;
}
