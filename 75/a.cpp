#include <cstdio>

int d[10];

inline int modify(int n) {
  int m = 0;

  while (n > 0) {
    d[m] = n % 10;
    n /= 10;
    ++m;
  }

  for (int i = m - 1; i >= 0; --i) {
    if (d[i] > 0) {
      n = n * 10 + d[i];
    }
  }

  return n;
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b);

  if (modify(a) + modify(b) == modify(a + b)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
