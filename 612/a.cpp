#include <cstdio>

const int N = 123;
char s[N];

int main() {
  int n, p, q, x, y;
  bool solvable = false;
  scanf("%d%d%d%s", &n, &p, &q, s);
  for (int i = 0; i < N && ! solvable; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i * p + j * q == n) {
        solvable = true;
        x = i, y = j;
        break;
      }
    }
  }
  if ( ! solvable) {
    puts("-1");
    return 0;
  }
  printf("%d\n", x + y);
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < p; ++j) {
      putchar(s[i * p + j]);
    }
    putchar('\n');
  }
  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < q; ++j) {
      putchar(s[x * p + i * q + j]);
    }
    putchar('\n');
  }
  return 0;
}
