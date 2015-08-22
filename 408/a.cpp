#include <cstdio>
#include <algorithm>

const int N = 100;
int a[N];

int main() {
  int n, min_val = 1e9;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }

  for (int i = 0; i < n; ++i) {
    int tmp = 0, tmp2;

    for (int j = 0; j < a[i]; ++j) {
      scanf("%d", &tmp2);
      tmp += tmp2;
    }

    min_val = std::min(min_val, (tmp * 5) + (15 * a[i]));
  }

  printf("%d\n", min_val);
  return 0;
}
