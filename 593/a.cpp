#include <cstdio>
#include <cstring>

const int N = 1234, M = 26;
char s[N][N];

int main() {
  int n, ans = 0, curr, len;
  bool ok;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < M; ++j) {
      curr = 0;
      for (int k = 0; k < n; ++k) {
        ok = true, len = strlen(s[k]);
        for (int q = 0; q < len; ++q) {
          if (s[k][q] != 'a' + i && s[k][q] != 'a' + j) {
            ok = false;
            break;
          }
        }
        if (ok) {
          curr += len;
        }
      }
      if (curr > ans) {
        ans = curr;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
