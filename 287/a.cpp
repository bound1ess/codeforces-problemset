#include <cstdio>

const int N = 4, M = 10;
char paper[M][M];

int main() {
  bool ok = false;
  for (int i = 0; i < N; ++i) {
    scanf("%s", paper[i]);
  }
  for (int i = 0; ! ok && i < N - 1; ++i) {
    for (int j = 0; j < N - 1; ++j) {
      int a = 0, b;
      a += paper[i][j] == '#';
      a += paper[i + 1][j] == '#';
      a += paper[i][j + 1] == '#';
      a += paper[i + 1][j + 1] == '#';
      b = N - a;
      if (a <= 1 || b <= 1) {
        ok = true;
        break;
      }
    }
  }
  puts(ok ? "YES" : "NO");
  return 0;
}
