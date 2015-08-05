#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1234567;
int a[N];

inline int find_min(int i, int n) {
  if (i < 1) {
    return abs(a[i] - a[i + 1]);
  }

  if (i + 1 == n) {
    return abs(a[i] - a[i - 1]);
  }

  return min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1]));
}

inline int find_max(int i, int n) {
  return max(abs(a[i] - a[0]), abs(a[i] - a[n - 1]));
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }

  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", find_min(i, n), find_max(i, n));
  }

  return 0;
}
