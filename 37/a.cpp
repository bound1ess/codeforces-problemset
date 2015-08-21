#include <cstdio>
#include <algorithm>

const int N = 1000;
int a[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }

  std::sort(a, a + n);
  int max_h = 0, total = 0, curr_h = 1;

  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      ++curr_h;
      continue;
    }

    max_h = std::max(curr_h, max_h);
    ++total, curr_h = 1;
  }

  if (curr_h > 0) {
    max_h = std::max(curr_h, max_h);
    ++total;
  }

  printf("%d %d\n", max_h, total);
  return 0;
}
