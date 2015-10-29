#include <cstdio>

const int N = 123, M = 10;
int d[N];

inline bool check(int m, int s) {
  return s >= 0 && 9 * m >= s;
}

inline void build_min(int m, int s) {
  int k = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < M; ++j) {
      if ((i > 0 || j > 0 || (m == 1 && j == 0)) && check(m - 1 - i, s - j)) {
        d[k] = j, ++k, s -= j;
        break;
      }
    }
  }
}

inline void build_max(int m, int s) {
  int k = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = M - 1; j >= 0; --j) {
      if ((i > 0 || j > 0 || (m == 1 && j == 0)) && check(m - 1 - i, s - j)) {
        d[k] = j, ++k, s -= j;
        break;
      }
    }
  }
}

int main() {
  int m, s;
  scanf("%d%d", &m, &s);
  if (s == 0 && m == 1) {
    puts("0 0");
    return 0;
  }
  if (s == 0 || 9 * m < s) {
    puts("-1 -1");
    return 0;
  }
  build_min(m, s);
  for (int i = 0; i < m; ++i) {
    printf("%d", d[i]);
  }
  putchar(' ');
  build_max(m, s);
  for (int i = 0; i < m; ++i) {
    printf("%d", d[i]);
  }
  putchar('\n');
  return 0;
}
