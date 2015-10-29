#include <cstdio>

const int N = 6;

inline int diff(int a, int b) {
  int c = a - b;
  return c < 0 ? -c : c;
}

int main() {
  int a, b, fp = 0, draw = 0, sp = 0;
  scanf("%d%d", &a, &b);
  for (int i = 1; i <= N; ++i) {
    int x = diff(i, a), y = diff(i, b);
    if (x < y) {
      ++fp;
    } else if (x > y) {
      ++sp;
    } else {
      ++draw;
    }
  }
  printf("%d %d %d\n", fp, draw, sp);
  return 0;
}
