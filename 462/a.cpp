#include <cstdio>

const int N = 123;
char s[N][N];

inline bool check(int x, int y, int n) {
  int adj = 0;
  if (x > 0) {
    adj += s[y][x - 1] == 'o';
  }
  if (x + 1 < n) {
    adj += s[y][x + 1] == 'o';
  }
  if (y > 0) {
    adj += s[y - 1][x] == 'o';
  }
  if (y + 1 < n) {
    adj += s[y + 1][x] == 'o';
  }
  return adj % 2 == 0;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ( ! check(j, i, n)) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}
