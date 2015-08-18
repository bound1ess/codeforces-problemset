#include <cstdio>

const int N = 100000;
int h[N];

int main() {
  int n, energy = 0, buy = 0;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", h + i);
  }

  for (int i = 0; i < n; ++i) {
    int jump = h[i] - h[i + 1];

    while (energy + jump < 0) {
      ++buy, ++jump;
    }

    energy += jump;
  }

  printf("%d\n", buy);
  return 0;
}
