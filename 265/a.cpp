#include <cstdio>
#include <cstring>

const int N = 123;
char s[N], t[N];

int main() {
  int ans = 0, n;
  scanf("%s%s", s, t);
  n = int(strlen(t));
  for (int i = 0; i < n; ++i) {
    if (t[i] == s[ans]) {
      ++ans;
    }
  }
  printf("%d\n", ans + 1);
  return 0;
}
