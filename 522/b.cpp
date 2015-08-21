#include <cstdio>

const int N = 200001;
int w[N], h[N];

int main() {
  int n, w_sum = 0, max_h1 = N, max_h2;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d%d", w + i, h + i);
    w_sum += w[i];

    if (h[max_h1] < h[i]) {
      max_h2 = max_h1;
      max_h1 = i;
    } else if (h[max_h2] < h[i]) {
      max_h2 = i;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (h[max_h1] == h[i]) {
      printf("%d", (w_sum - w[i]) * h[max_h2]);
    } else {
      printf("%d", (w_sum - w[i]) * h[max_h1]);
    }

    printf(i + 1 < n ? " " : "\n");
  }

  return 0;
}
