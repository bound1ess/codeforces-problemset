#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;
stack<int> r, s;

const int N = 2001;
int a[N], b[N];

int main() {
  int n, x, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    a[x] = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    b[i] = a[x];
  }
  for (int i = 1; i <= n; ++i) {
    int j = n;
    while (i != b[j]) {
      --j;
    }
    while (i != j) {
      int k = j - 1;
      while (b[k] < j) {
        --k;
      }
      swap(b[j], b[k]);
      r.push(j);
      s.push(k);
      ans += j - k;
      j = k;
    }
  }
  printf("%d\n%d\n", ans, (int) r.size());
  while ( ! r.empty()) {
    printf("%d %d\n", r.top(), s.top());
    r.pop();
    s.pop();
  }
  return 0;
}
