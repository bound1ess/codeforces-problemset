#include <iostream>
#include <map>

using namespace std;

const int N = 1234567;
int a[N];

int main() {
  long long n, k;
  map<long long, long long> l, r;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++r[a[i]];
  }

  long long ans = 0LL;

  for (int i = 0; i < n; ++i) {
    --r[a[i]];

    if (a[i] % k == 0) {
      ans += l[a[i] / k] * r[a[i] * k];
    }

    ++l[a[i]];
  }

  cout << ans << endl;
  return 0;
}
