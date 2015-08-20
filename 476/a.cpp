#include <cstdio>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  if (m > n) {
    printf("-1\n");
    return 0;
  }

  int s = (n / 2) + (n % 2);

  while (s < n && s % m != 0) {
    ++s;
  }

  printf("%d\n", s % m == 0 ? s : -1);
  return 0;
}
