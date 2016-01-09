#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 123456;
int a[N];

inline bool check(int n) {
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] > a[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  if (check(n)) {
    puts("YES");
    return 0;
  }
  for (int i = n - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] > a[i]) {
        swap(a[i], a[j]);
        puts(check(n) ? "YES" : "NO");
        return 0;
      }
    }
  }
  return 0;
}
