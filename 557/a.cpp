#include <cstdio>

const int N = 3;
int min[N], max[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < N; ++i) {
    scanf("%d %d", min + i, max + i);
  }

  int a = max[0], b = max[1], c = max[2];

  while (a + b + c != n) {
    if (c > min[2]) {
      --c;
    } else if (b > min[1]) {
      --b;
    } else {
      --a;
    }
  }

  printf("%d %d %d\n", a, b, c);
  return 0;
}
