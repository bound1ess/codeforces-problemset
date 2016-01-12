#include <cstdio>
#include <cstring>

const int N = (int) 1e6 + 100;
char a[N], b[N];

int main() {
  scanf("%s%s", a, b);
  int l = 0, r = 0, n = int(strlen(a)), m = int(strlen(b));
  while (a[l] == '0') {
    ++l;
  }
  while (b[r] == '0') {
    ++r;
  }
  n -= l;
  m -= r;
  if (n != m) {
    puts(n > m ? ">" : "<");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (a[l + i] != b[r + i]) {
      puts(a[l + i] > b[r + i] ? ">" : "<");
      return 0;
    }
  }
  puts("=");
  return 0;
}
