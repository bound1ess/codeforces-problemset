#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100;
int c[N][N], row_best[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", c[i] + j);
    }
  }
  for (int i = 0; i < n; ++i) {
    row_best[i] = *min_element(c[i], c[i] + m);
  }
  printf("%d\n", *max_element(row_best, row_best + n));
  return 0;
}
