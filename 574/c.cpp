#include <cstdio>

int main() {
  int n, x, first = -1;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);

    while (x % 2 == 0) {
      x /= 2;
    }

    while (x % 3 == 0) {
      x /= 3;
    }

    if (first == -1) {
      first = x;
    } else if (first != x) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
  return 0;
}
