#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n, m, x;
  scanf("%d%d", &n, &m);
  vector <int> a;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    a.push_back(x);
  }
  set <int> c;
  for (int i = n - 1; 0 <= i; --i) {
    c.insert(a[i]);
    a[i] = int(c.size());
  }
  vector <int> b;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &x);
    b.push_back(a[x - 1]);
  }
  for (int i = 0; i < m; ++i) {
    printf("%d\n", b[i]);
  }
  return 0;
}
