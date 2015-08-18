#include <cstdio>
#include <algorithm>

const int N = 1000;
int ids[N];

inline bool check_ok(int val, int streak) {
  return val > 0 && streak == 2;
}

inline bool check_fail(int val, int streak) {
  return val > 0 && streak > 2;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", ids + i);
  }

  std::sort(ids, ids + n);

  int ans = 0, val = ids[0], streak = 1;

  for (int i = 1; i < n; ++i) {
    if (ids[i] == val) {
      ++streak;
      continue;
    }

    if (check_fail(val, streak)) {
      printf("-1\n");
      return 0;
    }

    if (check_ok(val, streak)) {
      ++ans;
    }

    val = ids[i], streak = 1;
  }

  if (check_fail(val, streak)) {
    printf("-1\n");
  } else {
    if (check_ok(val, streak)) {
      ++ans;
    }

    printf("%d\n", ans);
  }

  return 0;
}
