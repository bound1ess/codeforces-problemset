#include <cstdio>

const int N = 20, M = 3;
int a[N], ans[M];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    ans[i % M] += a[i];
  }

  if (ans[0] > ans[1] && ans[0] > ans[2]) {
    printf("chest\n");
    return 0;
  }

  if (ans[1] > ans[0] && ans[1] > ans[2]) {
    printf("biceps\n");
  } else {
    printf("back\n");
  }

  return 0;
}
