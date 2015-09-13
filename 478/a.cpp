#include <cstdio>

const int N = 5;

int main() {
  int sum = 0, x;

  for (int i = 0; i < N; ++i) {
    scanf("%d", &x);
    sum += x;
  }

  printf("%d\n", sum % N == 0 && sum > 0 ? sum / N : -1);
  return 0;
}
