#include <cstdio>
#include <cstring>

const int N = 123456;
char s[N];

int main() {
  int zero = -1, n;
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      zero = i;
      break;
    }
  }
  if (zero == -1) {
    for (int i = 0; i < n - 1; ++i) {
      putchar('1');
    }
  } else {
    for (int i = 0; i < n; ++i) {
      if (i != zero) {
        putchar(s[i]);
      }
    }
  }
  putchar('\n');
  return 0;
}
