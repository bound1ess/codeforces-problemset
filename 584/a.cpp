#include <cstdio>

int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  if (n == 1 && t == 10) {
    puts("-1");
  } else {
    printf("%d", t);
    for (int i = 0; i < n - 1 - (t % 10 == 0); ++i) {
      printf("0");
    }
    puts("");
  }
  return 0;
}
