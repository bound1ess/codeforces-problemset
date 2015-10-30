#include <cstdio>
#include <cstring>

const int N = 1234, M = 26;
char s[N];
int w[M];

int main() {
  int k, n, max_w = 0, ans = 0;
  scanf("%s", s);
  n = strlen(s);
  scanf("%d", &k);
  for (int i = 0; i < M; ++i) {
    scanf("%d", w + i);
    if (w[i] > max_w) {
      max_w = w[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    ans += (i + 1) * w[s[i] - 'a'];
  }
  for (int i = n; i < n + k; ++i) {
    ans += (i + 1) * max_w;
  }
  printf("%d\n", ans);
  return 0;
}
