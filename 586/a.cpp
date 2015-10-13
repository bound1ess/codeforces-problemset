#include <cstdio>

const int N = 100;
int a[N];

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  int low = 0, high = n - 1;
  while (low < n && a[low] == 0) {
    ++low;
  }
  while (0 < high && a[high] == 0) {
    --high;
  }
  for (int i = low; i <= high; ++i) {
    if (a[i] == 1) {
      ++ans;
      continue;
    }
    int gap = 0;
    for (int j = i; j <= high && a[j] == 0; ++j) {
      ++gap;
    }
    if (gap >= 2) {
      i += gap - 1;
    } else {
      ans += gap;
    }
  }
  printf("%d\n", ans);
  return 0;
}
