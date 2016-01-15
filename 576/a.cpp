#include <cstdio>

const int N = 1234;
bool p[N];
int a[N];

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    p[i] = true;
  }
  for (int i = 2; i * i <= n; ++i) {
    if (p[i]) {
      for (int j = i * i; j <= n; j += i) {
        p[j] = false;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (p[i]) {
      int j = 1;
      while (n / i >= j) {
        j *= i;
        a[ans] = j, ++ans;
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < ans; ++i) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", a[i]);
  }
  if (ans > 0) {
    putchar('\n');
  }
  return 0;
}
