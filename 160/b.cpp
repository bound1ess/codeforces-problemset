#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 333;
char s[N];
int a[N], b[N];

int main() {
  int n;
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
    b[i] = s[n + i] - '0';
  }
  sort(a, a + n);
  sort(b, b + n);
  bool less = true, larger = true;
  for (int i = 0; i < n; ++i) {
    if (b[i] <= a[i]) {
      less = false;
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] <= b[i]) {
      larger = false;
      break;
    }
  }
  puts(less || larger ? "YES" : "NO");
  return 0;
}
