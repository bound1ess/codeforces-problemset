#include <cstdio>

const int N = 100;
int a[N];

inline int max(int a, int b) {
  return a < b ? b : a;
}

inline int solve(int l, int r, int n) {
  int ans = 0;

  for (int i = l; i <= r; ++i) {
    a[i] = 1 - a[i];
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      ++ans;
    }
  }

  for (int i = l; i <= r; ++i) {
    a[i] = 1 - a[i];
  }

  return ans;
}

int main() {
  int n, ans = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i <= j) {
        ans = max(ans, solve(i, j, n));
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
