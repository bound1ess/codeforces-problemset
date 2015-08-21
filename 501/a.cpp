#include <cstdio>
#include <algorithm>

inline int compute(int p, int t) {
  return std::max(3 * p / 10, p - p / 250 * t);
}

int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);

  if (compute(a, c) == compute(b, d)) {
    printf("Tie\n");
  } else if (compute(a, c) > compute(b, d)) {
    printf("Misha\n");
  } else {
    printf("Vasya\n");
  }

  return 0;
}
