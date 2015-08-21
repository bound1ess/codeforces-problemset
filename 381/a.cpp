#include <cstdio>

const int N = 1000;
int a[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }

  int l = 0, r = n - 1, a_sum = 0, b_sum = 0, id = 0;
  int max;

  while (l <= r) {
    if (a[l] < a[r]) {
      max = a[r], r--;
    } else {
      max = a[l], l++;
    }

    if (id < 1) {
      a_sum += max;
    } else {
      b_sum += max;
    }

    id = 1 - id;
  }

  printf("%d %d\n", a_sum, b_sum);
  return 0;
}
