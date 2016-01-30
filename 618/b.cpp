#include <cstdio>

const int N = 123;
int a[N][N], max[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", a[i] + j);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] > max[i]) {
        max[i] = a[i][j];
      }
    }
  }
  bool rep = false;
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      putchar(' ');
    }
    if (max[i] != n - 1) {
      printf("%d", max[i]);
    } else if (rep) {
      printf("%d", n);
    } else {
      printf("%d", n - 1);
      rep = true;
    }
  }
  putchar('\n');
  return 0;
}
