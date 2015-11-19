#include <cstdio>
#include <set>

using namespace std;

int main() {
  set<int> xs, ys;
  int n, x, y;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    xs.insert(x), ys.insert(y);
  }
  if (int(xs.size()) == 2 && int(ys.size()) == 2) {
    int a, b, c, d;
    a = *(xs.begin()), b = *(++xs.begin());
    c = *(ys.begin()), d = *(++ys.begin());
    printf("%d\n", (b - a) * (d - c));
  } else {
    puts("-1");
  }
  return 0;
}
