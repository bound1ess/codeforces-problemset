#include <cstdio>

const int N = 123456;
int a[N];

inline bool check(int n) {
  bool asc = true, desc = true;
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] > a[i]) {
      asc = false;
      break;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] < a[i]) {
      desc = false;
      break;
    }
  }
  return asc || desc;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  if (check(n)) {
    puts("0");
    return 0;
  }
  for (int i = 1; i < n - 1; ++i) {
    if (a[i - 1] < a[i]) {
      for (int j = i + 1; j < n; ++j) {
        if (a[i] > a[j]) {
          puts("3");
          printf("%d %d %d\n", i, i + 1, j + 1);
          return 0;
        }
      }
    }
  }
  for (int i = 1; i < n - 1; ++i) {
    if (a[i - 1] > a[i]) {
      for (int j = i + 1; j < n; ++j) {
        if (a[i] < a[j]) {
          puts("3");
          printf("%d %d %d\n", i, i + 1, j + 1);
          return 0;
        }
      }
    }
  }
  return 0;
}
