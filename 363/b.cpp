#include <cstdio>

const int N = 1234567;
int a[N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; ++i) {
    a[i] += a[i - 1];
  }
  int ans_idx = 0, ans_sum = (int) 1e9;
  for (int i = 0; i < n - k + 1; ++i) {
    int sum = a[i + k - 1] - (0 < i ? a[i - 1] : 0);
    if (sum < ans_sum) {
      ans_idx = i;
      ans_sum = sum;
    }
  }
  printf("%d\n", ans_idx + 1);
  return 0;
}
