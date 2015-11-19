#include <iostream>
#include <cmath>

using namespace std;

const int N = 200000;
int a[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long ans = abs(a[0]);
  for (int i = 1; i < n; ++i) {
    ans += abs(a[i] - a[i - 1]);
  }
  cout << ans << endl;
  return 0;
}
