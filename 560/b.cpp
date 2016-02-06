#include <cstdio>

inline void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

inline int max(int a, int b) {
  return a < b ? b : a;
}

int main() {
  int a, b, c, d, e, f;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (max(c, f) <= a && d + e <= b) {
          puts("YES");
          return 0;
        }
        swap(c, d);
      }
      swap(e, f);
    }
    swap(a, b);
  }
  puts("NO");
  return 0;
}
