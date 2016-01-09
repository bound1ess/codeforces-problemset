#include <cstdio>

inline bool check(int a, int b) {
  int c = 0;
  while (a > 0) {
    int d = a % 10;
    a /= 10;
    if (d == 4 || d == 7) {
      c = c * 10 + d;
    }
  }
  int d = 0;
  while (c > 0) {
    d = d * 10 + (c % 10);
    c /= 10;
  }
  return b == d;
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  do {
    ++a;
  } while ( ! check(a, b));
  printf("%d\n", a);
  return 0;
}
