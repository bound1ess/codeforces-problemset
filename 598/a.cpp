#include <iostream>

using namespace std;

const int N = 123;
long long a[N];

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < t; ++i) {
    long long ans = a[i] * (a[i] + 1ll) / 2ll;
    for (long long j = 1ll; j <= a[i]; j *= 2ll) {
      ans -= j * 2ll;
    }
    cout << ans << endl;
  }
  return 0;
}
