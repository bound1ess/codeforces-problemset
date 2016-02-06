#include <cstdio>
#include <vector>

using namespace std;

inline void go(const vector <int> &v, int x, int n, int &ans) {
  for (int i = 0; i < x; ++i) {
    int sum = 0;
    for (int j = i; j < n; j += x) {
      sum += v[j];
    }
    if (ans < sum) {
      ans = sum;
    }
  }
}

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  vector <int> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
    ans += v[i];
  }
  for (int i = 1; i <= n / 3; ++i) {
    if (n % i == 0) {
      go(v, i, n, ans);
    }
  }
  printf("%d\n", ans);
  return 0;
}
