#include <cstdio>

const int N = 123456;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  bool ok = true;
  int pos;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i + 1] < a[i]) {
      pos = i + 1;
      ok = false;
      break;
    }
  }
  if (ok) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < pos - 1; ++i) {
    if (a[i + 1] < a[i]) {
      puts("-1");
      return 0;
    }
  }
  for (int i = pos; i < n - 1; ++i) {
    if (a[i + 1] < a[i]) {
      puts("-1");
      return 0;
    }
  }
  printf("%d\n", a[n - 1] <= a[0] ? n - pos : -1);
  return 0;
}
