#include <cstdio>

int main() {
  int n, x;
  scanf("%d", &n);
  bool has_one = false;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (x == 1) {
      has_one = true;
    }
  }
  printf("%d\n", has_one ? -1 : 1);
  return 0;
}
