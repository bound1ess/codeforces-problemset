#include <cstdio>
#include <cstring>

const int N = 123456;
int l[N], r[N], dp[N];
char s[N];

int main() {
  scanf("%s", s);
  int n = int(strlen(s)), m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", l + i, r + i);
  }
  for (int i = 1; i < n; ++i) {
    if (s[i - 1] == s[i]) {
      ++dp[i];
    }
    dp[i] += dp[i - 1];
  }
  for (int i = 0; i < m; ++i) {
    printf("%d\n", dp[r[i] - 1] - dp[l[i] - 1]);
  }
  return 0;
}
