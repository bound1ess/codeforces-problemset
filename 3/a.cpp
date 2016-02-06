#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 123;
char a[N], b[N];

int main() {
  scanf("%s%s", a, b);
  int x, y, c, d, ans;
  x = a[0] - 'a', y = a[1] - '0';
  c = b[0] - 'a', d = b[1] - '0';
  ans = max(abs(x - c), abs(y - d));
  printf("%d\n", ans);
  for (int i = 0; i < ans; ++i) {
    if (c < x) {
      putchar('L');
      --x;
    } else if (x < c) {
      putchar('R');
      ++x;
    }
    if (d < y) {
      putchar('D');
      --y;
    } else if (y < d) {
      putchar('U');
      ++y;
    }
    putchar('\n');
  }
  return 0;
}
