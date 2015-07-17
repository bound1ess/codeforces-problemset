#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 15;
int arr[N], n, l, r, x;

int solve(int at = 0, int elems = 0, int total = 0, int min_diff = 1e9, int max_diff = -1e9) {
  if (at == n) {
    return (int) (elems > 1 && total >= l && total <= r && (max_diff - min_diff) >= x);
  }

  return solve(at + 1, elems, total, min_diff, max_diff)
    + solve(at + 1, elems + 1, total + arr[at], min(arr[at], min_diff), max(arr[at], max_diff));
}

int main() {
  scanf("%d %d %d %d", &n, &l, &r, &x);

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  printf("%d\n", solve());
  return 0;
}
