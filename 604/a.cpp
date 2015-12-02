#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 5;
int m[N], w[N];

int main() {
  int score = 0, x, a, b;
  for (int i = 0; i < N; ++i) {
    scanf("%d", m + i);
  }
  for (int i = 0; i < N; ++i) {
    scanf("%d", w + i);
  }
  scanf("%d%d", &a, &b);
  for (int i = 0; i < N; ++i) {
    x = (i + 1) * 500;
    score += max(x / 10 * 3, (250 - m[i]) * x / 250 - 50 * w[i]);
  }
  score += 100 * a - 50 * b;
  printf("%d\n", score);
  return 0;
}
