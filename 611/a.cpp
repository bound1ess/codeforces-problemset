#include <cstring>
#include <cstdio>

const int N = 123;
char s[N];

int main() {
  int x;
  scanf("%d%s%s", &x, s, s);
  if (strcmp(s, "week") == 0) {
    printf("%d\n", x == 5 || x == 6 ? 53 : 52);
  } else {
    if (x <= 29) {
      puts("12");
    } else {
      printf("%d\n", x == 30 ? 11 : 7);
    }
  }
  return 0;
}
