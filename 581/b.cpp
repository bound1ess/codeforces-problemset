#include <cstdio>

const int N = 1e5;
int h[N], max[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", h + i);
  }
  max[n - 1] = h[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    max[i] = h[i] > max[i + 1] ? h[i] : max[i + 1];
  }
  for (int i = 0; i < n - 1; ++i) {
    printf("%d ", h[i] > max[i + 1] ? 0 : max[i + 1] - h[i] + 1);
  }
  puts("0");
  return 0;
}
