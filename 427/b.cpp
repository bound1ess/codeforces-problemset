#include <iostream>

using namespace std;

const int N = 200200;
int a[N];

int main() {
  int n, t, c, x, len = 0;
  long long ans = 0LL;
  cin >> n >> t >> c;
  a[len] = -1, ++len;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (x > t) {
      a[len] = i, ++len;
    }
  }
  a[len] = n, ++len;
  for (int i = 1; i < len; ++i) {
    int diff = a[i] - a[i - 1] - 1;
    int tmp = diff - c + 1;
    if (tmp >= 0) {
      ans += (long long) tmp;
    }
  }
  cout << ans << endl;
  return 0;
}
