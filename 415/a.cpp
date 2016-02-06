#include <cstdio>

const int N = 123;
int lights[N], btn[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", btn + i);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = btn[i] - 1; j < n; ++j) {
      if (lights[j] == 0) {
        lights[j] = btn[i];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (0 < i) {
      putchar(' ');
    }
    printf("%d", lights[i]);
  }
  putchar('\n');
  return 0;
}
