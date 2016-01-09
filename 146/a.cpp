#include <cstdio>

const int N = 123;
char s[N];

int main() {
  int n, a = 0, b = 0;
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; ++i) {
    if (s[i] != '4' && s[i] != '7') {
      puts("NO");
      return 0;
    }
  }
  for (int i = 0, j = n - 1; i < j; ++i, --j) {
    if (j - i == 1) {
      puts(s[i] + a == b + s[j] ? "YES" : "NO");
      return 0;
    } else {
      a += s[i];
      b += s[j];
    }
  }
  return 0;
}
