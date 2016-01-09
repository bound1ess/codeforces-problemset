#include <cstdio>
#include <set>

using namespace std;

inline bool check(int a, int b) {
  set<int> d;
  while (a > 0) {
    d.insert(a % 10);
    a /= 10;
  }
  while (b > 0) {
    if (d.count(b % 10) > 0) {
      return true;
    }
    b /= 10;
  }
  return false;
}

int main() {
  int x, ans = 0;
  scanf("%d", &x);
  set<int> d;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      d.insert(i);
      d.insert(x / i);
    }
  }
  for (auto i = d.begin(); i != d.end(); ++i) {
    if (check(x, *i)) {
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
