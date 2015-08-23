#include <cstdio>
#include <algorithm>

const int N = 200000;
int a[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    a[i] += i;
  }

  std::sort(a, a + n);

  for (int i = 0; i < n; ++i) {
    a[i] -= i;
  }

  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > a[i + 1]) {
      printf(":(\n");
      return 0;
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    printf("%d ", a[i]);
  }

  printf("%d\n", a[n - 1]);
  return 0;
}
