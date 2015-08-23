#include <cstdio>
#include <algorithm>

const int N = 3000;
int a[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }

  printf("%d\n", n);

  for (int i = 0; i < n; ++i) {
    int k = i;

    for (int j = i + 1; j < n; ++j) {
      if (a[j] < a[k]) {
        k = j;
      }
    }

    std::swap(a[i], a[k]);
    printf("%d %d\n", i, k);
  }

  return 0;
}
