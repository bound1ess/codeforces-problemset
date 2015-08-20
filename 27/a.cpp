#include <cstdio>

const int N = 3000;
bool has[N];

int main() {
  int n, x;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    has[x - 1] = true;
  }

  for (int i = 0; i < N; ++i) {
    if ( ! has[i]) {
      printf("%d\n", i + 1);
      return 0;
    }
  }

  printf("%d\n", N + 1);
  return 0;
}
