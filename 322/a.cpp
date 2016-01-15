#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%d\n", n + m - 1);
  for (int i = 1; i < n + m; ++i) {
    printf("%d %d\n", max(i - m + 1, 1), min(m, i));
  }
  return 0;
}
