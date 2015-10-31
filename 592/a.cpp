#include <cstdio>

const int N = 8, M = 10;
char a[M][M];

int main() {
  int best_a = 123, best_b = 123;
  for (int i = 0; i < N; ++i) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (a[i][j] == 'W') {
        int curr = 0;
        bool ok = true;
        for (int k = i - 1; k >= 0; --k) {
          if (a[k][j] != '.') {
            ok = false;
            break;
          }
          ++curr;
        }
        if (ok && curr < best_a) {
          best_a = curr;
        }
      }
      if (a[i][j] == 'B') {
        int curr = 0;
        bool ok = true;
        for (int k = i + 1; k < N; ++k) {
          if (a[k][j] != '.') {
            ok = false;
            break;
          }
          ++curr;
        }
        if (ok && curr < best_b) {
          best_b = curr;
        }
      }
    }
  }
  if (best_a == best_b) {
    puts("A");
  } else {
    puts(best_a < best_b ? "A" : "B");
  }
  return 0;
}
