#include <cstdio>

const int N = 123456;
int a[N];

int main() {
  int n, min_idx = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    if (a[min_idx] > a[i]) {
      min_idx = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i != min_idx && a[i] == a[min_idx]) {
      puts("Still Rozdil");
      return 0;
    }
  }
  printf("%d\n", min_idx + 1);
  return 0;
}
