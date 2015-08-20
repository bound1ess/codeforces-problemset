#include <cstdio>

int main() {
  int n, x, odd = 0, even = 0, last_odd = -1, last_even = -1;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);

    if (x % 2 == 0) {
      ++even, last_even = i + 1;
    } else {
      ++odd, last_odd = i + 1;
    }
  }

  printf("%d\n", odd < even ? last_odd : last_even);
  return 0;
}
