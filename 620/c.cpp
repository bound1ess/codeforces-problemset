#include <cstdio>
#include <set>

using namespace std;

const int N = 1234567;
int a[N], l[N], r[N];

int main() {
  int n, ans = 0, lpos = 0;
  set <int> u;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; ++i) {
    if (u.find(a[i]) != u.end()) {
      u.clear();
      l[ans] = lpos;
      r[ans] = i;
      ++ans, lpos = i + 1;
    } else {
      u.insert(a[i]);
    }
  }
  if (ans > 0) {
    r[ans - 1] = n - 1;
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i) {
      printf("%d %d\n", l[i] + 1, r[i] + 1);
    }
  } else {
    puts("-1");
  }
  return 0;
}
