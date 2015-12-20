#include <cstdio>

const int N = 123456;
int a[N];

int main() {
  int n, l = 0, r = 0, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    sum += a[i];
  }
  sum /= n;
  for (int i = 0; i < n; ++i) {
    if (a[i] < sum) {
      l += sum - a[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (sum < a[i]) {
      r += a[i] - sum - 1;
    }
  }
  printf("%d\n", l < r ? r : l);
  return 0;
}
