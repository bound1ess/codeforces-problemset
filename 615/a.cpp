#include <cstdio>

const int N = 123;
bool btn[N];

int main() {
  int n, m, x, y;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    for (int j = 0; j < x; ++j) {
      scanf("%d", &y);
      btn[y - 1] = true;
    }
  }
  for (int i = 0; i < m; ++i) {
    if ( ! btn[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
