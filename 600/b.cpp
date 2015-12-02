#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200100;
int a[N], b[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", b + i);
  }
  sort(a, a + n);
  for (int i = 0; i < m; ++i) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", (int) (upper_bound(a, a + n, b[i]) - a));
  }
  putchar('\n');
  return 0;
}
