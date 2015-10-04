#include <cstdio>
#include <set>
#include <vector>

std::multiset<int> s;
std::vector<int> ans;

const int N = 500;
int a[N];

int gcd(int a, int b) {
  return b > 0 ? gcd(b, a % b) : a;
}

int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n * n; ++i) {
    scanf("%d", &x);
    s.insert(x);
  }
  for (int i = 0; i < n; ++i) {
    a[i] = *s.rbegin();
    ans.push_back(a[i]);
    s.erase(s.find(a[i]));
    for (int j = 0; j < i; ++j) {
      x = gcd(a[i], a[j]);
      s.erase(s.find(x));
      s.erase(s.find(x));
    }
  }
  for (int i = 0, m = ans.size(); i < m - 1; ++i) {
    printf("%d ", ans[i]);
  }
  printf("%d\n", ans[ans.size() - 1u]);
  return 0;
}
