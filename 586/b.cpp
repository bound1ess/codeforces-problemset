#include <cstdio>

const int N = 50;
int up[N], low[N], b[N];

int main() {
  int n, ans = 1e9;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d", up + i);
  }
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d", low + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b + i);
  }
  for (int i = 0; i < n; ++i) {
    int left = 0, right;
    for (int j = n - 2; j > n - i - 2; --j) {
      left += low[j];
    }
    for (int j = n - i - 2; j >= 0; --j) {
      left += up[j];
    }
    left += b[n - i - 1];
    for (int j = 0; j < n; ++j) {
      if (n - i - 1 == j) {
        continue;
      }
      right = 0;
      for (int k = 0; k < j; ++k) {
        right += up[k];
      }
      for (int k = j; k < n - 1; ++k) {
        right += low[k];
      }
      right += b[j];
      int total = left + right;
      if (total < ans) {
        ans = total;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
