#include <cstdio>

const int N = 123456;
bool used[N];

int main() {
  int n, k, l, r;
  scanf("%d%d", &n, &k);
  l = 0, r = n - 1;
  for (int i = 0; i < k; ++i) {
    if (i % 2 == 0) {
      used[l] = true;
      printf("%d ", l + 1);
      ++l;
    } else {
      used[r] = true;
      printf("%d ", r + 1);
      --r;
    }
  }
  if (k % 2 == 0) {
    for (int i = n - 1; i >= 0; --i) {
      if ( ! used[i]) {
        printf("%d ", i + 1);
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      if ( ! used[i]) {
        printf("%d ", i + 1);
      }
    }
  }
  putchar('\n');
  return 0;
}
